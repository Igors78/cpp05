/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:00:22 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/24 10:50:09 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentalPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>

int main(void)
{
	srand(time(NULL));
	{
		std::cout << "-----------Presidential Pardon----------" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		PresidentalPardonForm form001("Angela Davis");
		Bureaucrat max("Max Senges", 1);
		Bureaucrat jan("Jan Behrenbeck", 150);
		jan.executeForm(form001);
		max.signForm(form001);
		jan.signForm(form001);
		max.executeForm(form001);
		jan.executeForm(form001);
	}

	{
		std::cout << "-----------Robotomy Request-------------" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		RobotomyRequestForm form002("Compiler");
		Bureaucrat max("Max Senges", 1);
		Bureaucrat jan("Jan Behrenbeck", 150);
		max.executeForm(form002);
		jan.signForm(form002);
		max.signForm(form002);
		jan.executeForm(form002);
		max.executeForm(form002);
		max.executeForm(form002);
		max.executeForm(form002);
		max.executeForm(form002);
	}

	{
		std::cout << "-----------Shrubbery Creation-----------" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		ShrubberyCreationForm form003("Backyard");
		Bureaucrat max("Max Senges", 1);
		Bureaucrat jan("Jan Behrenbeck", 150);
		max.executeForm(form003);
		jan.signForm(form003);
		max.signForm(form003);
		jan.executeForm(form003);
		max.executeForm(form003);
	}
}