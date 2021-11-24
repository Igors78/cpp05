/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:00:22 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/24 07:28:03 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		Form form("Enrollment certificate", 10, 10);
		Bureaucrat max("Max Senges", 7);
		std::cout << max;
		std::cout << form;
		max.signForm(form);
		std::cout << form;
	}

	{
		Form form("Enrollment certificate", 100, 100);
		Bureaucrat jan("Jan Behrenbeck", 142);
		std::cout << jan;
		std::cout << form;
		jan.signForm(form);
	}

	{
		try
		{
			Form form("Form", 0, 0);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		try
		{
			Form form("Form", 160, 160);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}