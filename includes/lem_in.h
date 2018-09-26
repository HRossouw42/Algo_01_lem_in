/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:50:04 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/26 11:52:03 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"

typedef struct			s_link
{
	struct s_link		*next;
	struct s_room		*room;
}						t_link;

typedef struct			s_storage
{
	struct s_storage	*next;
	char				*ident;
	int					st_end;
}						t_storage;

typedef struct			s_paths
{
	struct s_storage	*route;
	struct s_paths		*next;
	struct s_paths		*compatable;
	struct s_paths		*checking;
	int					taken;
}						t_paths;

typedef struct			s_opt
{
	int					len_tot;
	struct s_paths		*routes;
	int					num_routes;
}						t_opt;

typedef struct			s_opt_path
{
	t_storage			*route;
	struct s_opt_path	*next;
	int					route_len;
}						t_opt_path;

typedef struct		s_room
{
	struct s_room	*next;
	char			*ident;
	char			*posx;
	char			*posy;
	int				is_start;
	int				is_end;
	int				num_of_lem;
	t_link			*connect;
	t_link			*start_connections;
	t_storage		*backpack;
	int				routes_needed;
	t_paths			*routes;
}					t_room;

typedef struct			s_ant
{
	char				*name;
	struct s_ant		*next;
	t_room				*room;
	t_storage			*route;
	int					moves;
}						t_ant;

t_room					*receive();
void					error(void);
void					add_to_room_end(t_room **start, t_room *new);
void					add_link_to_end(t_link **start, t_room *new);
int						link_create(t_room **room, char **line);
void					init_routes(t_room **room);
void					calc_routes_needed(t_room **room);
void					ant_move(t_room *room, t_storage *backpack);
void					move_ant(t_room **rooms, t_opt_path *best, t_ant *ant);
void					no_overlaps(t_paths **start);
t_opt					*find_opt(t_paths **start);
void					simulation(t_room **rooms, t_opt *best);
t_ant					*ant_create(t_room **rooms);

t_room					*find_start(t_room **room);
t_room					*find_end(t_room **room);

void					print_store(t_storage *storage);
void					leave_storage(t_room *room, t_storage *storage);
t_storage				*copy_storage(t_storage *storage);
void					add_room_storage(t_room *room, t_storage **storage);
int						is_stored(char *ident, t_storage *storage);

t_room					*make_room(char **input, int start_end, int num_of_ant);
int						has_char(char **line, char c);
int						is_num(char *str);

void					error_empty(int num_of_ant);
void					gnf(char **line);
void					sharp(char **line);
void					add_to_list(t_opt_path **start, t_storage *bp, \
	int len);
void					check_move(t_paths *checking, t_paths *smallest, \
		int i, int j);
int						len_store(t_storage *storage);

#endif
