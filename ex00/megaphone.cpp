/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:18:51 by datran            #+#    #+#             */
/*   Updated: 2023/09/15 11:53:31 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>

int main(int ac, char *av[]) {
    if (ac == 1) {
        puts("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
        return 0;
    }
    for (int i = 1; i < ac; i++) {
        int len = std::strlen(av[i]);
        for (int j = 0; j < len; j++)
            av[i][j] = ::toupper(av[i][j]);
        std::cout << av[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
