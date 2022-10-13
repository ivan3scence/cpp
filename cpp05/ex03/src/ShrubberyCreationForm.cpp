#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(void)
		: Form("ShrubberyCreationForm", 0, 145, 137),
		_target("no-target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
		: Form("ShrubberyCreationForm", 0, 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &shrub)
{
	*this = shrub;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator =
											(ShrubberyCreationForm const &shrub)
{
	if (this == &shrub)
		return (*this);
	_target = shrub.getTarget();
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->Form::checkExecGrade(executor.getGrade());
	ShrubberyCreationForm::_draw();
}

void	ShrubberyCreationForm::_draw(void) const
{
	std::ofstream	os;

	os.open(_target + "-shrubbery");
	os << "                                              .\n"
		  "                                   .         ;\n"
		  "      .              .              ;%     ;;\n"
		  "        ,           ,                :;%  %;\n"
		  "         :         ;                   :;%;'     .,\n"
		  ",.        %;     %;            ;        %;'    ,;\n"
		  "  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
		  "   %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
		  "    ;%;      %;        ;%;        % ;%;  ,%;'\n"
		  "     `%;.     ;%;     %;'         `;%%;.%;'\n"
		  "      `:;%.    ;%%. %@;        %; ;@%;%'\n"
		  "         `:%;.  :;bd%;          %;@%;'\n"
		  "           `@%:.  :;%.         ;@@%;'\n"
		  "             `@%.  `;@%.      ;@@%;\n"
		  "               `@%%. `@%%    ;@@%;\n"
		  "                 ;@%. :@%%  %@@%;\n"
		  "                   %@bd%%%bd%%:;\n"
		  "                     #@%%%%%:;;\n"
		  "                     %@@%%%::;\n"
		  "                     %@@@%(o);  . '\n"
		  "                     %@@@o%;:(.,'\n"
		  "                 `.. %@@@o%::;\n"
		  "                    `)@@@o%::;\n"
		  "                     %@@(o)::;\n"
		  "                    .%@@@@%::;\n"
		  "                    ;%@@@@%::;.\n"
		  "                   ;%@@@@%%:;;;.\n"
		  "               ...;%@@@@@%%:;;;;,..    Gilo97\n"
		  "\n"
		  "------------------------------------------------\n"
		  "\n";
	os.close();
}