/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:28:51 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/24 09:12:01 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form()
	: _name("Default"), _gradeToSign(150), _gradeToExecute(150), _signed(false)
{
}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
		this->_gradeToExecute = rhs.getGradeToExecute();
		this->_gradeToSign = rhs.getGradeToSign();
		this->_signed = rhs.isSigned();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
	o << "Form name: " << i.getName() << std::endl;
	o << "Grade to sign: " << i.getGradeToSign() << std::endl;
	o << "Grade to execute: " << i.getGradeToExecute() << std::endl;
	o << "Form signed: " << i.isSigned() << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
char const *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

char const *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

char const *Form::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else
	{
		std::cout << this->getName() << " getting signed by "
				  << b.getName() << std::endl;
		this->_signed = true;
	}
}

void Form::canExecute(Bureaucrat const &executor) const
{
	if (this->_signed == false)
		throw Form::FormNotSignedException();
	else if (executor.getGrade() > this->_gradeToExecute)
		throw Form::GradeTooLowException();
	std::cout << executor.getName() << " execute " << this->_name << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
const std::string &Form::getName() const
{
	return (this->_name);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

bool Form::isSigned() const
{
	return (this->_signed);
}
/* ************************************************************************** */