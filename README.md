Pipex. :

# ./pipex infile cmd1 cmd2 outfile
pipe()
 |
 |-- fork()
      |
      |-- child // cmd1
      :     |--dup2()
      :     |--close end[0]
      :     |--execve(cmd1)
      :
      |-- parent // cmd2
            |--dup2()
            |--close end[1]
            |--execve(cmd2)
 



1. La fonction pipe() est appelée pour créer un canal de communication unidirectionnel entre deux processus. Le canal est représenté par une paire de descripteurs de fichiers, end[0] et end[1]. 
2. La fonction fork() est appelée pour créer un nouveau processus enfant. Le processus enfant exécute la première commande (cmd1) en utilisant la fonction execve(). 
3. Avant d'appeler execve(), le processus enfant utilise la fonction dup2() pour rediriger son entrée standard (stdin) à partir du descripteur de fichier end[0], qui est connecté à la sortie du processus parent. 
4. Le processus enfant ferme le descripteur de fichier end[1], car il n'en a pas besoin. 
5. Le processus parent, qui est le processus qui a appelé fork(), exécute la deuxième commande (cmd2) en utilisant la fonction execve(). 
6. Avant d'appeler execve(), le processus parent utilise la fonction dup2() pour rediriger sa sortie standard (stdout) à partir du descripteur de fichier end[1], qui est connecté à l'entrée du processus enfant. 
7. Le processus parent ferme le descripteur de fichier end[0], car il n'en a pas besoin. 
8. Les deux processus exécutent leurs commandes respectives et communiquent via le canal de communication créé par pipe(), de sorte que la sortie de cmd1 est transmise à l'entrée de cmd2. 
9. Le processus parent attend que le processus enfant se termine en utilisant la fonction wait(). 
10. Une fois que les deux processus ont terminé, le programme principal se termine. 


void    pipex(int f1, int f2)
{
    int   end[2];
    pid_t parent;
    pipe(end);
    parent = fork();
    if (parent < 0)
         return (perror("Fork: "));
    if (!parent) // if fork() returns 0, 
        child_process(f1, cmd1);
    else
        parent_process(f2, cmd2);
}

1. La fonction pipex() commence par créer un canal (pipe) avec la fonction système pipe() et stocke les descripteurs de fichiers de fin de canal dans un tableau end[2]. La fonction pipe() renvoie un tableau de deux descripteurs de fichiers : le descripteur de fichier end[0] sera utilisé pour la lecture et le descripteur de fichier end[1] pour l'écriture.

2. Ensuite, la fonction pipex() appelle fork() pour créer un nouveau processus enfant. Le PID du processus enfant est stocké dans la variable parent. Si fork() échoue, la fonction renvoie une erreur en affichant un message avec perror().

3. Si fork() réussit et retourne 0, cela signifie que le processus courant est le processus enfant. La fonction pipex() appelle alors une fonction child_process() qui exécute le premier programme (cmd1) en utilisant le descripteur de fichier f1 pour l'entrée et le descripteur de fichier end[1] pour la sortie.

4. Sinon, si fork() retourne une valeur positive différente de zéro, cela signifie que le processus courant est le processus parent. La fonction pipex() appelle alors une fonction parent_process() qui exécute le deuxième programme (cmd2) en utilisant le descripteur de fichier end[0] pour l'entrée et le descripteur de fichier f2 pour la sortie.

5. En résumé, cette fonction utilise les appels système pipe(), fork(), et deux fonctions child_process() et parent_process() pour créer deux processus distincts qui communiquent via un canal (pipe). Le premier processus écrit ses sorties dans le canal, qui est ensuite lu par le second processus pour effectuer ses opérations de sortie. Cela permet d'enchaîner deux commandes UNIX à la façon de la commande shell |.




//chaque cmd nécessite un stdin (entrée) et renvoie une sortie (vers stdout)
   
              infile                                                    outfile
comme stdin pour cmd1                    comme stdout pour cmd2            
       |                        PIPE                        ↑
       |           |---------------------------|            |
       ↓             |                       |              |
      cmd1   -->    end[1]       ↔       end[0]   -->     cmd2           
                     |                       |
            cmd1   |---------------------------|  end[0]
           output                             reads end[1]
         is written                          and sends cmd1
          to end[1]                          output to cmd2
       (end[1] becomes                      (end[0] becomes 
        cmd1 stdout)                           cmd2 stdin)

