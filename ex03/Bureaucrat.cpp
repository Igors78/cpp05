/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:00:32 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/24 08:18:16 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat()
	: _name("Default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << ", grade: " << i.getGrade() << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
char const *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

char const *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
	}

	catch (std::exception &e)
	{
		std::cerr << this->getName() << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cerr << this->getName() << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
const std::string &Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}
/* ************************************************************************** */