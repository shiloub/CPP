#include "main.hpp"


std::string get_date_pipe(std::string line)
{
	std::string date;
	int i(0);

	while (line[i] && line[i] != '|')
	{
		date.push_back(line[i]);
		i++;
	}
	return (date);
}

void	trim_spaces(std::string &date)
{
	while (date[date.size() - 1] == ' ')
		date.erase(date.size() - 1);
	while (date[0] == ' ')
		date.erase(0, 1);
}

std::string get_after_pipe(std::string line)
{
	std::string str;
	int i(0);

	while (line[i] && line[i] != '|')
		i++;
	if (line[i] == '|')
		i++;
	while (line[i])
	{
		str.push_back(line[i]);
		i++;
	}
	return (str);
}

int	check_date(std::string date)
{
	int count(0);
	int i(0);
	std::istringstream date_stream(date);
	std::string value;


	while (date[i])
	{
		if (date[i] == '-')
			count ++;
		i++;
	}
	if (count != 2)
		throw (std::runtime_error("Bad input"));
	i = 0;
	while (std::getline(date_stream, value, '-')) {
		if (i == 0) {
			if (value.size() != 4)
				throw (std::runtime_error("Year format isnt valid"));
			if (atoi(value.c_str()) < 2000 || atoi(value.c_str()) >= 2023)
				throw (std::runtime_error("Year isnt in range"));
		}
		if (i == 1) {
			if (value.size() != 2)
				throw (std::runtime_error("Month format isnt valid"));
			if (atoi(value.c_str()) < 1 || atoi(value.c_str()) > 12)
				throw (std::runtime_error("Month isnt in range"));
		}
		if (i == 2) {
			if (value.size() != 2)
				throw (std::runtime_error("Day format isnt valid"));
			if (atoi(value.c_str()) < 1 || atoi(value.c_str()) > 31)
				throw (std::runtime_error("Day isnt in range"));
		}
		i++;
	}
	return (1);
}
int	check_int_float(const char *value)
{
	std::string valid("123456789.");
	int point_count = 0;

	for (int i = 0; value[i] != 0; i++){
		while (value[i] == ' '){
			i++;
		}
		if (!value[i])
			return (0);
		if (value[i] == '.'){
			if (i == 0 || value[i - 1] == ' ' || !value[i + 1])
				return (0);
			else
				point_count++;
		}
		if (valid.find_first_of(value[i]) == std::string::npos)
			return (0);
	}
	if (point_count == 0 || point_count == 1)
		return (1);
	return (0);
}

int	check_line(std::string number)
{
	int i = 0;
	while (number[i] == ' ')
		i++;
	if ((number.length() - i) > 5 || atoi(number.c_str()) > 1000)
		throw (std::runtime_error("Number too large"));
	if (atof(number.c_str()) < 0)
		throw (std::runtime_error("Number under 0"));
	if (number == "" || !check_int_float(number.c_str()))
		throw (std::runtime_error("Bad input"));
	return (1);
}

void    convert(std::map<std::string, std::string> map, char *file)
{
	std::string line;
	std::string date;
	std::string number;
	std::map<std::string, std::string>::const_iterator it;

	std::ifstream flux(file);
	if (!flux)
	{
		std::cout << "impossible d'ouvrir le file input.txt\n";
		exit(0);
	}
	while (getline(flux, line))
	{
		date = get_date_pipe(line);
		trim_spaces(date);
		trim_spaces(number);
		number = get_after_pipe(line);
		it = map.find(date);
		if (it == map.end())
		{
			it --;
			if (date > it->first && date != "date") {
				std::cout << "Date out of range\n";
				date = "date";
			}
			it ++;
			it = map.upper_bound(date);
		}
		try
		{
			if (date != "date" && check_line(number) && check_date(date))
				std::cout << date << " => " << number << " * " << it->second << " = " << strtof(number.c_str(), NULL) * strtof(it->second.c_str(), NULL) << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}


int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Im waiting for one argument\n";
		return (0);
	}
	
	std::map<std::string , std::string> map = parsing();
	convert(map, av[1]);
}