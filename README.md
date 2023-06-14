# Pipex
Pipex est un projet de qui consiste à recréer le fonctionnement de l'opérateur de redirection de shell | en utilisant des pipes en C. Le programme Pipex prend en entrée un fichier source, exécute deux commandes et redirige la sortie de la première commande vers l'entrée de la seconde commande, en imitant le comportement de la commande shell 
    ```C command1 | command2.```

## Compilation
Pour compiler le projet Pipex, vous devez exécuter la commande suivante :
    `make`
Cela générera l'exécutable ***pipex***.

## Utilisation
Une fois que vous avez compilé le projet, vous pouvez l'utiliser en exécutant la commande suivante :
    ```./pipex file1 cmd1 cmd2 file2```
où :
***file1*** est le fichier source en entrée.
***cmd1***  est la première commande à exécuter.
***cmd2***  est la deuxième commande à exécuter.
***file2*** est le fichier de sortie où le résultat sera stocké.

## Exemple
Voici un exemple d'utilisation du programme Pipex :
    ```./pipex infile "ls -l" "grep pipex" outfile```
Ce commandera exécutera la commande ```ls -l``` sur le contenu du fichier infile, puis filtrera la sortie en utilisant la commande grep pipex, et enfin écrira le résultat final dans le fichier outfile.

## Bonus
Le projet Pipex offre également la possibilité de mettre en œuvre certains bonus supplémentaires. Voici une liste des bonus implémentés dans ce projet :

1. ***Gestion de multiples pipes*** : Le programme Pipex peut gérer plusieurs opérations de redirection en utilisant plusieurs pipes. Par exemple :
    ```./pipex infile "ls -l" "grep pipex" "sort -r" outfile```
2. ***Gestion de l'opérateur de redirection*** ```<``` : Le programme Pipex peut prendre en charge l'opérateur de redirection < pour lire le contenu d'un fichier en entrée. Par exemple :
    ```./pipex infile "< input.txt" "grep pipex" outfile```
2. ***Gestion de l'opérateur de redirection*** ```>``` : Le programme Pipex peut prendre en charge l'opérateur de redirection > pour écrire le résultat final dans un fichier de sortie. Par exemple :
    ```./pipex infile "ls -l" "grep pipex" "> output.txt"```
4. ***Gestion de l'opérateur de redirection*** ```>>``` : Le programme Pipex peut prendre en charge l'opérateur de redirection >> pour ajouter le résultat final à un fichier de sortie existant. Par exemple :
    ```./pipex infile "ls -l" "grep pipex" ">> output.txt"```

## Remarques
Assurez-vous que les commandes que vous utilisez sont correctement formatées et qu'elles sont accessibles depuis le répertoire où vous exécutez le programme Pipex.

## Auteur
Ce projet Pipex a été réalisé par moi;).


