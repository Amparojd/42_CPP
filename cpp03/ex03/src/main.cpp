#include "DiamondTrap.hpp"

int main() {
    // Crear DiamondTrap
    DiamondTrap diamondtrap("DIAM");
    diamondtrap.attack("target4");
    diamondtrap.takeDamage(15);
    diamondtrap.beRepaired(25);
    diamondtrap.whoAmI();

    return 0;
}
