/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentalPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 07:39:33 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/24 09:52:53 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentalPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentalPardonForm::PresidentalPardonForm()
	: Form("PresidentialPardonForm", 25, 5), _target("Default")
{
}

PresidentalPardonForm::PresidentalPardonForm(std::string const target)
	: Form("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentalPardonForm::PresidentalPardonForm(const PresidentalPardonForm &src)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentalPardonForm::~PresidentalPardonForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentalPardonForm &PresidentalPardonForm::operator=(PresidentalPardonForm const &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, PresidentalPardonForm const &i)
{
	o << "Target = " << i.getTarget();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void PresidentalPardonForm::execute(Bureaucrat const &executor) const
{
	this->canExecute(executor);
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/
const std::string &PresidentalPardonForm::getTarget() const
{
	return (this->_target);
}
/* ************************************************************************** */