/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:23:41 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/24 13:56:11 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Intern
{

public:
	Intern();
	Intern(Intern const &src);
	~Intern();

	Intern &operator=(Intern const &rhs);

	Form *makeForm(std::string const &form, std::string const &target) const;

	class InternException
		: public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	Form *makePresidentalPardonForm(std::string const &) const;
	Form *makeRobotomyRequestForm(std::string const &) const;
	Form *makeShrubberyCreationForm(std::string const &) const;
	Form *makeErrorForm(std::string const &) const;
};

std::ostream &operator<<(std::ostream &o, Intern const &i);

#endif /* ********************************************************** INTERN_H */