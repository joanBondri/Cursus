# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check_all.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <besellem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 15:50:59 by besellem          #+#    #+#              #
#    Updated: 2021/04/26 14:25:17 by jbondri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from generate import ft_gen_numbers
import os


if __name__ == "__main__":

	if not os.path.isfile("./push_swap"):
		print("\033[1;31mError:\033[0m push_swap does not exist (create executable first)")
		exit(1)
	if not os.path.isfile("./checker"):
		print("\033[1;31mError:\033[0m checker does not exist (create executable first)")
		exit(1)

	for i in range(0, 10):
		numbers_generated_lst = ft_gen_numbers(0, i)
		numbers_generated_str = ' '.join(map(str, numbers_generated_lst))
		print(numbers_generated_str)
		print(f'\033[1;36m# {i:3}\033[0m')
		# os.system(f'./push_swap {numbers_generated_str} | wc -l | tr -d " " ')
		os.system(f'./push_swap {numbers_generated_str} | ./checker {numbers_generated_str}')
