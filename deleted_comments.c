
/*в файле мэйн

size_t	get_time(void) //deleteme
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

в хэдере
size_t		get_time(void);

в draw_figure
size_t		time = get_time();
printf("%zu\n", get_time() - time);


*/

/*в функции main
print_scene_info(&rt);
size_t	time = get_time();

printf("%zu\n", get_time() - time);
*/

/*в файле rotating
printf("before: %f, %f, %f\n", rt->camera.normalized.x, rt->camera.normalized.y, rt->camera.normalized.z);
printf("after: %f, %f, %f\n", rt->camera.normalized.x, rt->camera.normalized.y, rt->camera.normalized.z);

printf("before: %f, %f, %f\n", rt->objects[rt->obj_index].normalized.x, rt->objects[rt->obj_index].normalized.y, rt->objects[rt->obj_index].normalized.z);
printf("after: %f, %f, %f\n", rt->objects[rt->obj_index].normalized.x, rt->objects[rt->obj_index].normalized.y, rt->objects[rt->obj_index].normalized.z);

printf("cylinder: %f, %f, %f\n", rt->objects[rt->obj_index].normalized.x, rt->objects[rt->obj_index].normalized.y, rt->objects[rt->obj_index].normalized.z);
printf("plane: %f, %f, %f\n", rt->objects[rt->obj_index].normalized.x, rt->objects[rt->obj_index].normalized.y, rt->objects[rt->obj_index].normalized.z);
*/

/*в функции init
ft_printf(2, "initiated\n");
*/

/*в функции validate_content
ft_printf(2, "validated\n");
*/

/*в функции move
//delete!
		printf("cylinder coords: %f, %f, %f\n", rt->objects[rt->obj_index].coords.x, rt->objects[rt->obj_index].coords.y, rt->objects[rt->obj_index].coords.z);
*/