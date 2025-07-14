#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function 
int displayMenu(void);
int searchByAtomicNumber(void);
int searchBySymbol(void);
int searchByName(void);
int searchByWeight(void);
char Block(int);
char Property(int);
void displayElementDetails(int, char, char);
void saveToFile(int);
void loadFromFile(void);

// Data: Periodic Table
char *elementNames[112] = {"Hydrogen","Helium","Lithium","Beryllium","Boron","Carbon","Nitrogen","Oxygen","Flourine","Neon",
        "Sodium", "Magnesium", "Aluminium", "Silicon", "Phosphorus", "Sulphur", "Chlorine", "Argon",
        "Potassium","Calcium","Scandium","Titanium","Vanadium","Chromium","Manganese","Iron","Cobalt","Nickel","Copper","Zinc",
        "Gallium","Germanium","Arsenic","Selenium","Bromine","Krypton",
        "Rubidium","Strontium","Yttrium","Zirconium","Niobium","Molybdenum","Technetium","Ruthenium","Rhodium","Palladium","Silver","Cadmium",
        "Indium","Tin","Antimony","Tellurium","Iodine","Xenon",
        "Cesium","Barium","Lanthanum","Cerium","Praseodymium","Neodymium","Promethium","Samarium","Europium","Gadolinium","Terbium","Dysprosium",
        "Holmium","Erbium","Thulium","Ytterbium","Lutetium",
        "Hafnium","Tantalum","Tungsten","Rhenium","Osmium","Iridium","Platinum","Gold","Mercury","Thallium","Lead","Bismuth","Polonium","Astatine","Radon",
        "Francium","Radium","Actinium","Thorium","Protactinium","Uranium","Neptunium","Plutonium","Americium","Curium","Berkelium",
        "Californium","Einsteinium","Fermium","Mendelevium","Nobelium","Lawrencium",
"Rutherfordium","Dubnium","Seaborgium","Bohrium","Hassium","Meitnerium","Darmstadtium","Roentgenium","Copernicium"};

char *elementSymbols[112] = {"H","He","Li","Be","B","C","N","O","F","Ne",
                     "Na","Mg","Al","Si","P","S","Cl","Ar",
                                         "K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr",
                                         "Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe",
                                         "Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu",
                                         "Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn",
                     "Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm",",Md","No","Lr",
                                        "Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn"};

float elementWeights[112] ={1.00,4.00,6.94,9.01,10.81,12.01,14.00,16.00,20.00,20.18,23.00,24.31,26.99,28.08,30.97,32.06,35.45,39.09,40.07,44.95,47.86,50.94,
                                        51.99,54.93,55.84,58.69,58.93,63.54,65.39,69.7,72.64,74.92,78.96,79.90,83.80,85.46,87.62,88.90,91.22,92.90,95.94,98.00,101.07,
                                        102.90,106.42,107.86,112.41,114.81,118.71,121.76,127.6,126.90,131.29,13.90,137.32,138.90,140.11,140.90,144.24,145.00,
                                        150.36,151.96,157.25,158.92,162.50,164.93,167.5,168.93,173.04,174.96,178.49,180.94,183.84,186.20,190.23,192.21,195.07,196.97,
                                        200.59,204.38,207.20,208.98,209.00,210.00,222.00,223.00,226.00,227.00,231.03,232.03,237.00,238.03,243,244,247,247,251,252,257,258,
                                        259,261,262,264,266,268,272,277,276,281,280,285};

int main(void) {
    int option, elementIndex;
    char block, property;
do {
        option = displayMenu();
        switch (option) {
            case 1: 
                elementIndex = searchByAtomicNumber(); 
                break;
            case 2: 
                elementIndex = searchBySymbol(); 
                break;
            case 3: 
                elementIndex = searchByName(); 
                break;
            case 4: 
                elementIndex = searchByWeight(); 
                break;
            case 5:
                saveToFile(elementIndex); 
                break;
            case 6:
                loadFromFile(); 
                break;
 
            case 7: 
                printf("\nExiting program. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
                continue;
        }

        if (elementIndex == -1) {
            printf("\nElement not found. Please try again.\n");
        } else {
            block = Block(elementIndex);
            property = Property(elementIndex);
            displayElementDetails(elementIndex, block, property);
        }
    } while (option != 5);

    return 0;
}

// Display menu 
int displayMenu(void) {
    int choice;
    printf("\n=== Periodic Table Search ===\n");
    printf("1. Search by Atomic Number\n");
    printf("2. Search by Symbol\n");
    printf("3. Search by Name\n");
    printf("4. Search by Atomic Weight\n");
    printf("5. Save The Search History\n");
    printf("6. Load The History\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Search by atomic number
int searchByAtomicNumber(void) {
    int atomicNumber;
    printf("\nEnter the atomic number: ");
    scanf("%d", &atomicNumber);
    if (atomicNumber >= 1 && atomicNumber <= 112) {
        return atomicNumber - 1; 
    } else {
        return -1;
    }
}

// Search by symbol
int searchBySymbol(void) {
    char symbol[5];
    printf("\nEnter the atomic symbol: ");
    scanf("%s", symbol);
    for (int i = 0; i < 112; i++) {
        if (strcmp(symbol, elementSymbols[i]) == 0) {
            return i;
        }
    }
    return -1;
}

// Search by name
int searchByName(void) {
    char name[20];
    printf("\nEnter the atomic name: ");
    scanf("%s", name);
    for (int i = 0; i < 112; i++) {
        if (strcmp(name, elementNames[i]) == 0) {
            return i;
        }
    }
    return -1;
}

// Search by weight
int searchByWeight(void) {
    float weight;
    printf("\nEnter the atomic weight: ");
    scanf("%f", &weight);

    for (int i = 0; i < 112; i++) {
        if (abs(elementWeights[i] - weight) < 0.01) { 
            return i;
        }
    }
    return -1;
}


// Determine block type (s, p, d, f)
char Block(int index) {
    int atomicNumber = index + 1;
    if (atomicNumber == 1 || atomicNumber == 3 || atomicNumber == 4 || 
        (atomicNumber >= 11 && atomicNumber <= 12)) {
        return 's';
    } else if ((atomicNumber >= 5 && atomicNumber <= 10) || 
               (atomicNumber >= 13 && atomicNumber <= 18)) {
        return 'p';
    } else if ((atomicNumber >= 21 && atomicNumber <= 30)) {
        return 'd';
    } else {
        return 'f';
    }
}

// Determine metallic property
char Property(int index) {
    int atomicNumber = index + 1;
    if (atomicNumber == 1 || atomicNumber == 2 || 
        (atomicNumber >= 6 && atomicNumber <= 10)) {
        return 'n'; // Non-metal
    } else if (atomicNumber == 5 || atomicNumber == 14) {
        return 's'; // Metalloid
    } else {
        return 'm'; // Metal
    }
}

// Display element details
void displayElementDetails(int index, char block, char property) {
    printf("\n=== Element Details ===\n");
    printf("Atomic Number: %d\n", index + 1);
    printf("Symbol: %s\n", elementSymbols[index]);
    printf("Name: %s\n", elementNames[index]);
    printf("Weight: %.2f\n", elementWeights[index]);
    printf("Block: %c\n", block);
    printf("Property: ");
    if (property == 'n') {
        printf("Non-Metal\n");
    } else if (property == 's') {
        printf("Metalloid\n");
    } else {
        printf("Metal\n");
    }
}

void saveToFile(int index) {
    FILE *file = fopen("elements.txt", "a"); // Open in append mode
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "Atomic Number: %d\n", index + 1);
    fprintf(file, "Symbol: %s\n", elementSymbols[index]);
    fprintf(file, "Name: %s\n", elementNames[index]);
    fprintf(file, "Weight: %.2f\n", elementWeights[index]);
    fprintf(file, "-------------------------\n");

    fclose(file);
    printf("Element details saved to 'elements.txt'.\n");
}

void loadFromFile() {
    FILE *file = fopen("elements.txt", "r"); // Open in read mode
    if (file == NULL) {
        printf("No saved element data found.\n");
        return;
    }

    char line[100];
    printf("\n=== Saved Elements ===\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

