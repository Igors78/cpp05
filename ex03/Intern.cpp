/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:23:49 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/24 14:24:10 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentalPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &Intern::operator=(Intern const &rhs)
{
	//if ( this != &rhs )
	//{
	//this->_value = rhs.getValue();
	//}
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &o, Intern const &i)
{
	//o << "Value = " << i.getValue();
	(void)i;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
Form *Intern::makeForm(std::string const &form, std::string const &target) const
{
	Form *new_form;
	int i = 0;
	Form *(Intern::*forms[4])(std::string const &) const = {&Intern::makePresidentalPardonForm,
															&Intern::makeRobotomyRequestForm,
															&Intern::makeShrubberyCreationForm,
															&Intern::makeErrorForm};
	std::string request[3] = {
		"ppf",
		"rrf",
		"scf"};
	while (request[i].compare(form) && i < 3)
		i++;
	new_form = (this->*forms[i])(target);
	std::cout << "Intern creates " << new_form->getName() << std::endl;
	return (new_form);
}

Form *Intern::makePresidentalPardonForm(std::string const &target) const
{
	Form *new_form = new PresidentalPardonForm(target);
	return (new_form);
}

Form *Intern::makeRobotomyRequestForm(std::string const &target) const
{
	Form *new_form = new RobotomyRequestForm(target);
	return (new_form);
}

Form *Intern::makeShrubberyCreationForm(std::string const &target) const
{
	Form *new_form = new ShrubberyCreationForm(target);
	return (new_form);
}

const char *Intern::InternException::what() const throw()
{
	return "Unknown form!";
}

Form *Intern::makeErrorForm(std::string const &) const
{
	Form *new_form = NULL;
	throw Intern::InternException();
	return (new_form);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */