#include <fstream>
#include <iostream>

void	error(std::string str)
{
	std::cout << str << ": error!\n";
	exit(1);
}

std::string	replace(std::string line, std::string find, std::string repl, size_t pos)
{
	std::string	left;

	if (pos == std::string::npos)
		return (line);
	left = &line[pos + find.length()];
	return (line.substr(0, pos) + repl + replace(left, find, repl, left.find(find)));
}

int main(int argc, char **argv)
{
	std::ifstream	i_stream;
	std::ofstream	o_stream;
	std::string		line;
	char			flag;

	flag = 0;
	if (argc < 4)
	{
		std::cout << "wrong number of arguments!\n";
		exit(1);
	}
	i_stream.open(argv[1], std::ios::in);
	if (!i_stream.is_open())
		error(argv[1]);
	o_stream.open(std::string(argv[1]) + ".replace", std::ios::trunc);
	if (!o_stream.is_open())
		error(std::string(argv[1]) + ".replace");
	while (std::getline(i_stream, line))
	{
		if (flag)
			o_stream << std::endl;
		else
			flag = 1;
		line = replace(line, argv[2], argv[3], line.find(argv[2]));
		o_stream << line;
	}
	i_stream.close();
	o_stream.close();
}
