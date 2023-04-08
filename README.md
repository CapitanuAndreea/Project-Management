# Proiect_OOP
Temă: Project Management\
Student: Andreea Căpitanu, grupa 143
## Clasele implementate
* class Array - folosită drept substituitor pentru std::vector din STL, ce permite alocarea dinamică a unui vector
* class Angajat - poate reține numele, anul angajării și departamentul unui angajat\
                - permite schimbarea departamentului din care face parte un angajat\
                - calculează salariului unui angajat în funcție de anii săi vechime
* class Task - reține numele taskului, angajatul căruia i-a fost atribuit și statusul\
             - permite schimbarea statusului taskului (ex. din "Not started" în "In progress")
* class Necesitati - poate reține numele, prețul per bucată și numărul de bucăți aferent resursei necesare în realizarea proiectului\
                   - permite schimbarea numărului de bucăți al unei resurse
* class Proiect - reține echipa de angajați, lucrurile necesare, lista de taskuri și feedbackul fiecărui angajat cu privire la proiect\
                - permite calcularea bugetului necesar cumpărării tuturor bunurilor\
                - poate calcula feedbackul mediu oferit de angajați (o notă de la 1 la 5) pentru a îmbunătăți calitatea proiectului
