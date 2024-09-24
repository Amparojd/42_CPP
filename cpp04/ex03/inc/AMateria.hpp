#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

// Define colors
#define RESET       "\033[0m"
#define RED         "\033[91m"
#define GREEN       "\033[92m"
#define YELLOW      "\033[93m"
#define CYAN        "\033[96m"
#define PURPLE      "\033[95m"
#define GRAY        "\033[90m"
#define BOLD        "\033[1m"
#define ITALIC      "\033[3m"

class AMateria {
protected:
    std::string m_type;  // Prefijo m_ para el miembro de la clase
public:
    AMateria(std::string const & type);
    virtual ~AMateria();
    std::string const & getType() const;
    virtual AMateria* clone() const = 0; // Método puro
    virtual void use(ICharacter& target);
};

#endif
