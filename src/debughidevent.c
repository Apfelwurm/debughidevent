/*
 *
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * ***** END GPL LICENSE BLOCK *****
 *
 * Contributor(s): Apfelwurm <volzit.de>
 *
 */


#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/input.h>
#include <string.h>

int main( int argc, char *argv[] )  {
    int fd;
    struct input_event evt;


    if( argc == 2 ) {
        printf("The argument supplied is %s\n", argv[1]);
    }
    else if( argc > 2 ) {
        printf("Too many arguments supplied.\n");
        exit(1);
    }
    else {
        printf("One argument expected.\n");
        exit(1);
    }


    fd = open(argv[1], O_RDWR);
    ioctl(fd, EVIOCGRAB, 1);


    while(read(fd, &evt, sizeof(struct input_event)) > 0) {

          printf("key detected: Keycode %d , value %d, type %d, time %d\n", evt.code, evt.value, evt.type, evt.time);
    }


}



