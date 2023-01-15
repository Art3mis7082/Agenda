
# Digital diary
Project for Data Structures and Algorithms 1, semester 2023-1

To see this file on Spanish click [here](https://github.com/Art3mis7082/Agenda/blob/main/README.md)

> Disclaimer: This project don't have all the functions, it's intended to be a base project in constant development

### About the project
This project have the purpose to be a digital diary that can be personalized as the client's needs. Also have the objective to use data structures and algorithms seen on the semester. We used language C, and most of all of the functions are documented with doxygen.
For now it has the visualize of the calendar and events, create and delete contacts and events and it works only for the present year: 2023.

<img src="https://github.com/Art3mis7082/Agenda/blob/main/Agenda.PNG" width="380px" align="left">

### Compilation steps

The first step is to download the project (It can be downloaded as a ZIP file or open on [Github desktop](https://desktop.github.com)), then on the console we need to insert the command line `gcc main.c menu.c agenda.c contactos.c fechas.c -o ejecutable`. This command is going to generate the executable of diary (this isn't a virus, trust me). At the end, search the executable generated on the project folder, and there is. Diary is created. :Smiley:

Other way is to use the makefile that is on project folder, i am not sure, but it only works for Linux systems and macOS.
