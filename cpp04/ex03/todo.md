                   +----------------+
                   |  ICharacter    | interfaz pura para gestionar personajes
                   +----------------+
                            ^
                            |
                            |
                   +----------------+
                   |  Character     | Clase padre
                   +----------------+
                            |
                +-----------+-----------+
                |                       |
         +--------------+        +--------------+
         |     Ice      |        |     Cure     |
         +--------------+        +--------------+


                   +----------------+
                   | IMateriaSource | interfaz pura para gestionar materias
                   +----------------+
                            ^
                            |
                            |
                   +----------------+
                   | MateriaSource  |
                   +----------------+

                   +----------------+
                   |    AMateria    | Clase abstracta para los tipos de materias
                   +----------------+
                            ^
                            |
                            |
                +-----------+-----------+
                |                       |
         +--------------+        +--------------+
         |     Ice      |        |     Cure     |
         +--------------+        +--------------+
