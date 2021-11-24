/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 07:40:05 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/24 10:52:24 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("ShrubberyCreationForm", 145, 137), _target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i)
{
	o << "Target = " << i.getTarget();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->canExecute(executor);
	std::ofstream file;
	file.open(("./" + this->_target + "_shrubbery").c_str());
	for (int i = 0; i < 10; i++)
	{
		file << "              ,@@@@@@@,               " << std::endl;
		file << "      ,,,.   ,@@@@@@/@@,  .oo8888o.   " << std::endl;
		file << "   ,&%%&%&&%,@@@@@/@@@@@@,888888/8o  " << std::endl;
		file << "  ,%&%&&%&&%,@@@@@@/@@@8888888/88$$$' " << std::endl;
		file << "  %&&%&%&/%&&%@@@@/ /@@@8888888888$$' " << std::endl;
		file << "  %&&%/ %&%%&&@@ V /@@' `88\\8 `/88'  " << std::endl;
		file << "  `&% ` /%&'    |.|        \\ '|8'    " << std::endl;
		file << "     |o|        | |         | |       " << std::endl;
		file << "     |.|        | |         | |       " << std::endl;
		file << "    / ._\\//_/_/  ,\\_//___/.  \\_//__/" << std::endl;
		file << std::endl;
	}
	file.close();
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/
const std::string &ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

/* ************************************************************************** */