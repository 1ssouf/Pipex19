# Pipex
Ce projet est une simulation de la commande "pipe" de bash, permettant de rediriger la sortie standard d'une commande vers l'entrée standard d'une autre commande. Le but de ce projet est de comprendre le fonctionnement des pipes et de la redirection des entrées/sorties en C.

## Utilisation
Le programme doit être lancé avec la commande suivante :

    ./pipex infile cmd1 cmd2 outfile

où infile est le nom du fichier d'entrée, cmd1 est la première commande à exécuter, cmd2 est la deuxième commande à exécuter et outfile est le nom du fichier de sortie.

Par exemple, pour exécuter la commande :

    ls -l | grep pipex > result.txt 
on fait :
		
    ./pipex infile "ls -l" "grep pipex" outfile

## Fonctionnement
Le programme utilise deux processus fils pour exécuter les commandes cmd1 et cmd2 séparément et un tube pour communiquer entre eux. Le processus parent lit le fichier d'entrée infile et écrit dans l'entrée standard du processus fils cmd1 via le tube. Le processus fils cmd1 exécute la commande cmd1 et écrit le résultat dans la sortie standard via le tube. Le processus parent lit la sortie standard du processus fils cmd1 via le tube et écrit dans l'entrée standard du processus fils cmd2. Le processus fils cmd2 exécute la commande cmd2 et écrit le résultat dans le fichier de sortie outfile.

**Ci-dessous un schéma du fonctionnement :**

    pipe()
     |
     |-- fork()
          |
          |-- child // cmd1
          :     |--dup2()
          :     |--close end[0]
          :     |--execve(cmd1)
          :
          |-- parent
          :     |--dup2()
          :     |--close ends[1]
          :     |--read infile
          :     |--write to pipe
          :     |--read from pipe
          :     |--dup2()
          :     |--close ends[0]
          :
          |-- child // cmd2
                |--dup2()
                |--close end[1]
                |--execve(cmd2)
## Compilation
Le programme peut être compilé en lançant la commande make à la racine du projet. Cette commande va créer un exécutable pipex.

### Auteur
Ce projet a été réalisé par **Issouf Bello** dans le cadre de la formation à l'école 19.
