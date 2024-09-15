#!/bin/bash

{
    for i in {0..7}; do
        echo "ADD"
        echo "Contact$i"
        echo "LastName$i"
        echo "Nickname$i"
        echo "123456789$i"
        echo "Secret$i"
    done
    echo "SEARCH"   # Esto te deja en el modo de búsqueda después de agregar
} | ./myphonebook