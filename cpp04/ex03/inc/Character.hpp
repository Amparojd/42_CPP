#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
private:
    std::string m_name;
    AMateria* m_inventory[4]; // Inventario de 4 Materias
public:
    Character(std::string const & name);
    virtual ~Character();
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
    // Funciones de copia
    Character(const Character& other);
    Character& operator=(const Character& other);
};

#endif
