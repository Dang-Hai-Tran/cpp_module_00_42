/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:18:51 by datran            #+#    #+#             */
/*   Updated: 2023/06/13 19:06:34 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>

int main(int ac, char *av[]) {
    if (ac == 1) {
        puts("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
        return 0;
    }
    for (int i = 1; i < ac; i++) {
        std::transform(av[i], av[i] + std::strlen(av[i]), av[i],
                       [](const unsigned char& c){ return std::toupper(c); });
        std::cout << av[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
