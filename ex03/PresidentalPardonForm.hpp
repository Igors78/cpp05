/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentalPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 07:39:41 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/24 09:19:19 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTALPARDONFORM_HPP
#define PRESIDENTALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class PresidentalPardonForm
	: public Form
{

public:
	PresidentalPardonForm();
	PresidentalPardonForm(std::string const _target);
	PresidentalPardonForm(PresidentalPardonForm const &src);
	~PresidentalPardonForm();

	PresidentalPardonForm &operator=(PresidentalPardonForm const &rhs);

	void execute(Bureaucrat const &executor) const;
	const std::string &getTarget() const;

private:
	std::string _target;
};

std::ostream &operator<<(std::ostream &o, PresidentalPardonForm const &i);

#endif /* ******************************************* PRESIDENTALPARDONFORM_H */