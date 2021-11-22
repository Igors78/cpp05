/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:00:22 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/22 11:28:46 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat max("Max Senges", 1);
	Bureaucrat jan("Jan Behrenbeck", 150);

	std::cout << max;
	std::cout << jan;

	try
	{
		max.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		jan.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << max;
	std::cout << jan;
	try
	{
		max.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		jan.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << max;
	std::cout << jan;
	try
	{
		Bureaucrat mist("Mistake", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}