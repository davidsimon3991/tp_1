/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
struct
{
    int id;
    char name[51];
    char lastName[51];
    int isEmpty;

}typedef Employee;


int employee_compare(void*,void*);
void employee_print(Employee* this);
void employee_printEmployees(ArrayList*);
Employee* employee_new(void);
Employee* employee_new_withData(int,char*,char*,int);
Employee* employee_alta(ArrayList*);
void employee_delete(ArrayList*);
int employee_setId(Employee* this, int);
int employee_getId(ArrayList*,int);
int buscarID(ArrayList*,int);
#endif // _EMPLOYEE_H



