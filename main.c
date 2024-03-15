#include "medicos.h"
#include "pacientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){
    Medico *medico1 = addMedico("Dr. Joao", "Cardiologista", "Maria", "Segunda-feira");
    Medico *medico2 = addMedico("Dr. Pedro", "Ortopedista", "Jose", "Terca-feira");
    listMedicos(medico1);
    listMedicos(medico2);
    return 0;
}
