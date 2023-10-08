#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>

int main(){
	std::ifstream input_energy_now("/sys/class/power_supply/BAT0/energy_now");
	std::ifstream input_energy_full( "/sys/class/power_supply/BAT0/energy_full");
	std::string str_energy_now;
	std::string str_energy_full;
	long  energy_now;
	long  energy_full;
	double energy_percent;
	if (!input_energy_now.good() || !input_energy_full.good()){
		std::cerr << "Invalid files" << std::endl;
		return -1;
	}
	std::getline(input_energy_now, str_energy_now);
	std::getline(input_energy_full, str_energy_full);
	energy_now = atol(str_energy_now.c_str());
	energy_full = atol(str_energy_full.c_str());
	energy_percent = ((double)energy_now / energy_full) * 100;
	std::cout << (int) energy_percent << "%" <<std::endl;
}
