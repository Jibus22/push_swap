#include "push_swap.h"

void	print_mv(t_moves *mv)
{
	printf("````````````````````````````````````````\n");
	printf("_____A______--index: %d\tway: %d\tmoves: %d\n",
		mv->index_a, mv->way_a, mv->moves_a);
	printf("_____B______--index: %d\tway: %d\tmoves: %d\n",
		mv->index_b, mv->way_b, mv->moves_b);
	printf("___COMMON___--way: %d\tmoves: %d\ttotal_mv: %d\n",
		mv->common_way, mv->common_moves, mv->total_moves);
	printf("___UTILS____--init: %d\tway_b_after: %d\t\n",
		mv->init, mv->way_b_after);
	printf("````````````````````````````````````````\n");
	fflush(stdout);
}

void	init_move(t_moves *mv)
{
	mv->init = 0;
	mv->index_a = 0;
	mv->way_a = 0;
	mv->moves_a = 0;
	mv->index_b = 0;
	mv->way_b = 0;
	mv->way_b_after = 0;
	mv->moves_b = 0;
	mv->common_moves = 0;
	mv->common_way = 0;
	mv->total_moves = 0;
}

int	move_cpy(t_moves *src, t_moves *dst)
{
	dst->init = src->init;
	dst->index_a = src->index_a;
	dst->way_a = src->way_a;
	dst->moves_a = src->moves_a;
	dst->index_b = src->index_b;
	dst->way_b = src->way_b;
	dst->way_b_after = src->way_b_after;
	dst->moves_b = src->moves_b;
	dst->common_moves = src->common_moves;
	dst->common_way = src->common_way;
	dst->total_moves = src->total_moves;
	return (0);
}
