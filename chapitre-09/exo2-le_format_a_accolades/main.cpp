#include <iostream>
#include <string>

int main() {
std::string format;
if (!std::getline(std::cin, format)) return 0;
int nombreargument;
std::cin >> nombreargument;
int argument[100];
for (int i = 0; i < nombreargument; i++) {
std::cin >> argument[i];
    }

int remplaces = 0;
int manquants = 0;
std::string resultat = "";
 int i = 0;
while (i < format.length()) {
    if (format[i] == '{' && i + 2 < format.length() && format[i+2] == '}' && format[i+1] >= '0' && format[i+1] <= '9') {
int index = format[i+1] - '0';
if (index < nombreargument) {
resultat += std::to_string(argument[index]);
remplaces++;
} else {
resultat += format[i];
resultat += format[i+1];
resultat += format[i+2];
 manquants++;
            }
     i += 3; 
} else {
 resultat += format[i];
i++;
        }
    }
std::cout << resultat << "\n";
std::cout << "REMPLACES " << remplaces << "\n";
std::cout << "MANQUANTS " << manquants << "\n";
return 0;
}