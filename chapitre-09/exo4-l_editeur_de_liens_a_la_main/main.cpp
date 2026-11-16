#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    if (!(std::cin >> n)) return 0;
std::vector<std::string> fichiers(n);
std::vector<std::string> g_syms, stat_all, emp_all;
 for (int i = 0; i < n; ++i) {
std::cin >> fichiers[i];
int nd; std::cin >> nd;
for (int j = 0; j < nd; ++j) {
 std::string s; int f; std::cin >> s >> f;
if (f == 1) stat_all.push_back(fichiers[i] + "_" + s);
else g_syms.push_back(s);}
 int ne; std::cin >> ne;
for (int j = 0; j < ne; ++j) {
std::string s; std::cin >> s;
 emp_all.push_back(fichiers[i] + "_" + s); }
    }
std::vector<std::string> ind, doubs;
 for (const auto& e : emp_all) {
 std::string file = e.substr(0, e.find('_'));
std::string sym = e.substr(e.find('_') + 1);
bool found = false;
for (const auto& gs : g_syms) if (gs == sym) found = true;
for (const auto& st : stat_all) if (st == file + "_" + sym) found = true;
 bool deja = false;
for (const auto& x : ind) if (x == sym) deja = true;
if (!found && !deja) ind.push_back(sym);
    }

for (size_t i = 0; i < g_syms.size(); ++i) {
int cnt = 0;
for (size_t j = 0; j < g_syms.size(); ++j) if (g_syms[j] == g_syms[i]) cnt++;
if (cnt > 1) {
bool deja = false;
for (const auto& x : doubs) if (x == g_syms[i]) deja = true;
if (!deja) doubs.push_back(g_syms[i]); }
}
for (auto& s : ind) std::cout << "INDEFINI " << s << "\n";
for (auto& s : doubs) std::cout << "DOUBLE " << s << "\n";
std::cout << "INDEFINIS " << ind.size() << "\n";
 std::cout << "DOUBLES " << doubs.size() << "\n";
if (ind.empty() && doubs.empty()) std::cout << "VERDICT LIE\n";
else std::cout << "VERDICT ECHEC\n";
 return 0;
}