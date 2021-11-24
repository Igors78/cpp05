/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 07:39:58 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/24 09:43:35 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class RobotomyRequestForm
	: public Form
{

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const _target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

	void execute(Bureaucrat const &executor) const;
	const std::string &getTarget() const;

private:
	std::string _target;
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i);

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */