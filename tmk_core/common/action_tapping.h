/*
Copyright 2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef ACTION_TAPPING_H
#define ACTION_TAPPING_H



/* period of tapping(ms) */
#ifndef TAPPING_TERM
#define TAPPING_TERM    250
#endif

/* tap count needed for toggling a feature */
#ifndef TAPPING_TOGGLE
#define TAPPING_TOGGLE  2
#endif

#define WAITING_BUFFER_SIZE 8


#ifndef NO_ACTION_TAPPING
void action_tapping_process(keyrecord_t record);
#endif

#endif
