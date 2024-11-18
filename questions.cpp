#include "questions.h"
#include <stdexcept>

using namespace std;

vector<Question> questions = {
    {"¿Cuándo acabó la II Guerra Mundial?", {"En 1950", "En 1945", "En 1939", "En 1947"}, 1},
    {"¿Cuál era el apellido de la reina Isabel II de Inglaterra?", {"Lancaster", "Stuart", "Windsor", "Tudor"}, 2},
    {"¿En qué año se aprobó la actual Constitución española?", {"En 1980", "En 1975", "En 1976", "En 1978"}, 3},
    {"¿Qué día es la fiesta de la Hispanidad?", {"El 15 de octubre", "El 10 de octubre", "El 18 de octubre", "El 12 de octubre"}, 3},
    {"¿Cuál fue el primer presidente democrático de España tras la dictadura franquista?", {"Santiago Carrillo", "Felipe González", "Leopoldo Calvo-Sotelo", "Adolfo Suárez"}, 3},
    {"¿En qué año murió Freddie Mercury?", {"En 1990", "En 1991", "En 1989", "En 1993"}, 1},
    {"¿Qué día es la fiesta nacional de Estados Unidos?", {"El 1 de julio", "El 3 de julio", "El 5 de julio", "El 4 de julio"}, 3},
    {"¿Quién inventó la bombilla?", {"Nikola Tesla", "Alexander Graham Bell", "Thomas Edison", "Galileo Galilei"}, 2},
    {"¿En qué país se usó la primera bomba atómica?", {"Corea del Norte", "Japón (Hiroshima)", "Alemania", "Rusia"}, 1},
    {"¿Cuándo empezó la Primera Guerra Mundial?", {"En 1916", "En 1912", "En 1914", "En 1913"}, 2},
    {"¿En qué año se produjo la Revolución Francesa?", {"En 1789", "En 1795", "En 1785", "En 1790"}, 0},
    {"¿Cuántas veces ha estado el hombre en la Luna?", {"Tres", "Ocho", "Seis", "Cinco"}, 2},
    {"¿Qué presidente de Estados Unidos fue asesinado en Dallas?", {"William McKinley", "James Garfield", "Abraham Lincoln", "John F. Kennedy"}, 3},
    {"¿En qué año viajó al espacio el primer ser humano?", {"En 1959", "En 1957", "En 1961", "En 1963"}, 2},
    {"¿En qué año llegó Cristóbal Colón a América?", {"En 1500", "En 1490", "En 1485", "En 1492"}, 3},
    {"¿Cuándo saltó Felix Baumgartner?", {"En 2009", "En 2015", "En 2012", "En 2010"}, 2},
    {"¿En qué año cayó el muro de Berlín?", {"En 1991", "En 1989", "En 1987", "En 1990"}, 1},
    {"¿Cuándo se inventó la imprenta?", {"En 1450", "En 1440", "En 1460", "En 1430"}, 1},
    {"¿Hace cuánto se extinguieron los dinosaurios?", {"Hace 66 millones de años", "Hace 65 millones de años", "Hace 70 millones de años", "Hace 60 millones de años"}, 0},
    {"¿Cuál era el nombre de pila de Che Guevara?", {"Esteban", "Enrique", "Eduardo", "Ernesto"}, 3},
    {"Según la Biblia, ¿cuántos años vivió Matusalén?", {"900 años", "969 años", "950 años", "925 años"}, 1},
    {"¿En qué país nació Adolf Hitler?", {"Alemania", "Hungría", "Austria", "Polonia"}, 2},
    {"¿Qué reina británica fue hija de los Reyes Católicos?", {"Catalina de Aragón", "María Tudor", "Ana Bolena", "Isabel I"}, 0},
    {"¿Cuánto duró “La Guerra de los Cien Años”?", {"100 años", "120 años", "116 años", "90 años"}, 2},
    {"¿Quién fue el último faraón de Egipto?", {"Cleopatra VII", "Ramsés II", "Tutankamón", "Ramsés III"}, 3},
    {"¿Cuál fue la primera civilización humana?", {"Egipcia", "Sumeria", "Griega", "China"}, 1},
    {"¿Cuándo empezó la Revolución Rusa?", {"En 1917", "En 1918", "En 1916", "En 1920"}, 0},
    {"¿Cuál fue el genocidio más grande de la historia?", {"El Holodomor", "El Holocausto", "El genocidio armenio", "La matanza de Nankín"}, 1},
    {"¿Quién creó el Partido Comunista?", {"Marx", "Stalin", "Lenin", "Trotski"}, 2},
    {"¿Qué famoso líder de Cuba estuvo 49 años en el poder?", {"Raúl Castro", "Ernesto Guevara", "Camilo Cienfuegos", "Fidel Castro"}, 3},
    {"¿Cuándo se fundó la OTAN?", {"En 1945", "En 1950", "En 1949", "En 1955"}, 2},
    {"¿En qué año fue asesinado Abraham Lincoln?", {"En 1865", "En 1860", "En 1869", "En 1863"}, 0},
    {"¿En qué año se hundió el Titanic?", {"En 1910", "En 1912", "En 1914", "En 1911"}, 1},
    {"¿Con cuántos años murió la Reina Isabel II?", {"Con 96 años", "Con 94 años", "Con 92 años", "Con 98 años"}, 0},
    {"¿Cómo se llamaba en realidad El Cid Campeador?", {"Rodrigo Díaz de Vivar", "Álvar Fáñez", "Pedro Bermúdez", "Sancho II"}, 0},
    {"¿En qué año fue el golpe de Estado de Tejero?", {"En 1981", "En 1980", "En 1983", "En 1979"}, 0},
    {"¿Cuál fue el primer metal que el hombre empleó?", {"El hierro", "El oro", "El cobre", "La plata"}, 2},
    {"¿Qué personaje fue conocido como el rey de Macedonia?", {"Darío III", "Filipo II", "Alejandro Magno", "Ptolomeo I"}, 2},
    {"¿Alrededor de qué mar vivieron los egipcios, los fenicios, los israelitas, los griegos y los romanos?", {"El mar Rojo", "El mar Egeo", "El mar Mediterráneo", "El mar Negro"}, 2},
    {"Según la leyenda, ¿quiénes fundaron Roma?", {"Rómulo y Remo", "Julio César y Augusto", "Júpiter y Marte", "Eneas y Turno"}, 0},
    {"¿En qué año se coronó a Isabel II?", {"1948", "1953", "1956", "1960"}, 1},
    {"¿En qué año abdicó el rey Juan Carlos I?", {"En 2010", "En 2012", "En 2014", "En 2016"}, 2},
    {"¿En qué continente surgió la Humanidad?", {"América", "África", "Asia", "Europa"}, 1},
    {"¿En qué año cayó el Imperio Romano?", {"En el año 400", "En el año 476", "En el año 450", "En el año 490"}, 1},
    {"¿En qué etapa desaparecieron los dinosaurios?", {"Al final del Jurásico", "Al final del Triásico", "Al final del Cretácico", "Al inicio del Paleógeno"}, 2},
    {"¿Quién descubrió Perú?", {"Hernán Cortés", "Cristóbal Colón", "Francisco Pizarro", "Vasco Núñez de Balboa"}, 2},
    {"¿Dónde nació Adolf Hitler?", {"En Alemania", "En Austria", "En Suiza", "En Polonia"}, 1},
    {"¿Quién fue el primer emperador romano?", {"César Augusto", "Julio César", "Tiberio", "Nerón"}, 0},
    {"¿En qué año murió Napoleón?", {"En 1821", "En 1805", "En 1815", "En 1830"}, 0},
    {"¿Cuándo empezó la Primera Guerra Mundial?", {"En 1914", "En 1915", "En 1913", "En 1916"}, 0},
    {"¿Dónde se encuentra la Sagrada Familia?", {"En Madrid", "En Valencia", "En Sevilla", "En Barcelona"}, 3},
    {"¿Cuál es el océano más grande del mundo?", {"El océano Pacífico", "El océano Ártico", "El océano Índico", "El océano Atlántico"}, 0},
    {"¿Cuál es el país más grande del mundo?", {"Rusia", "Canadá", "Estados Unidos", "China"}, 0},
    {"¿Cuál es el país más poblado de la Tierra?", {"India", "Estados Unidos", "China", "Brasil"}, 2},
    {"¿Cuál es la ciudad de los rascacielos?", {"Nueva York", "Tokio", "París", "Londres"}, 0},
    {"¿En qué provincia de España se encuentra el parque temático de Port Aventura?", {"Tarragona", "Valencia", "Madrid", "Barcelona"}, 0},
    {"¿Dónde está la Casa Blanca?", {"En Los Ángeles", "En Chicago", "En Nueva York", "En Washington D.C."}, 3},
    {"¿Cuál es el continente más extenso del planeta?", {"Asia", "América", "Europa", "África"}, 0},
    {"¿Qué país del mundo produce más vino?", {"Italia", "España", "Francia", "Argentina"}, 0},
    {"¿A cuántos kilómetros equivale una milla?", {"1.6 km", "1.2 km", "1.8 km", "2.0 km"}, 0},
    {"¿Dónde se inventó la pizza?", {"Roma", "Milán", "Venecia", "Nápoles"}, 3},
    {"¿Cuántas personas hay en el mundo?", {"6.800 millones", "7.870 millones", "5.600 millones", "8.500 millones"}, 1},
    {"¿Cuál es la línea más larga del metro de Madrid?", {"Línea 1", "Línea 12", "Línea 5", "Línea 2"}, 1},
    {"¿Cuál es el lugar más frío de la tierra?", {"Siberia", "La Antártida", "El Polo Norte", "El Polo Sur"}, 1},
    {"¿Cuál es el río más largo de Europa?", {"El Loira", "El Volga", "El Danubio", "El Tajo"}, 1},
    {"¿Dónde se encuentra el museo del Louvre?", {"En París", "En Berlín", "En Londres", "En Madrid"}, 0},
    {"¿En qué ciudad europea está el Atomium?", {"Ámsterdam", "Bruselas", "Viena", "París"}, 1},
    {"¿Cómo se llama el río más famoso de Egipto?", {"El Amazonas", "El Nilo", "El Tigris", "El Eúfrates"}, 1},
    {"¿Cuál es la montaña más alta del planeta?", {"El Aconcagua", "El Everest", "El Kilimanjaro", "El K2"}, 1},
    {"¿Cuál es el río más largo del planeta?", {"El Amazonas", "El Nilo", "El Yangtsé", "El Mekong"}, 0},
    {"¿En qué país se encuentra el desierto de Atacama?", {"Perú", "Chile", "Argentina", "Bolivia"}, 1},
    {"¿Cuál es la ciudad más poblada de Andalucía?", {"Córdoba", "Sevilla", "Granada", "Málaga"}, 1},
    {"¿En qué país se encuentra el rascacielos más alto del mundo?", {"China", "Emiratos Árabes Unidos", "Japón", "Estados Unidos"}, 1},
    {"¿Cuál es el continente más extenso del planeta?", {"América", "Asia", "Europa", "África"}, 1},
    {"¿Cuál es el país más poblado de África?", {"Sudáfrica", "Egipto", "Nigeria", "Etiopía"}, 2},
    {"¿De qué país es originario el café?", {"Brasil", "Colombia", "México", "Etiopía"}, 3},
    {"¿En qué ciudad se entrevistaron Hitler y Franco?", {"Berlín", "París", "Roma", "Hendaya"}, 3},
    {"¿De qué país se independizó Eslovenia?", {"Serbia", "Yugoslavia", "Croacia", "Austria"}, 1},
    {"¿A qué país pertenece la isla de Creta?", {"Grecia", "Chipre", "Turquía", "Italia"}, 0},
    {"¿Cuál es el país más visitado del mundo?", {"Italia", "Estados Unidos", "Francia", "España"}, 2},
    {"¿Qué cordillera separa Europa de Asia?", {"Los Alpes", "Los Pirineos", "Los Apeninos", "Los montes Urales"}, 3},
    {"¿Cuál es el país con menos habitantes del mundo?", {"Luxemburgo", "La Ciudad del Vaticano", "San Marino", "Mónaco"}, 1},
    {"¿Qué dos países separa el estrecho de Bering?", {"Estados Unidos y Rusia", "Canadá y Rusia", "Japón y China", "China y Estados Unidos"}, 0},
    {"¿A qué país pertenece Groenlandia?", {"Dinamarca", "Noruega", "Canadá", "Suecia"}, 0},
    {"¿Cuál es la moneda oficial de Japón?", {"Yuan", "Yen", "Won", "Ringgit"}, 1},
    {"¿Qué volcán sepultó la ciudad de Pompeya?", {"El Fuji", "El Stromboli", "El Etna", "El Vesubio"}, 3},
    {"¿Cuál era la ciudad más cercana a la central nuclear de Chernóbil?", {"Kiev", "Rostov", "Prípiat", "Moscú"}, 2},
    {"¿Dónde se queda lo que pasa en Las Vegas?", {"En Las Vegas", "En Los Ángeles", "En Nevada", "En Nueva York"}, 0},
    {"¿Cuál es la ciudad más poblada del mundo?", {"Ciudad de México", "Pekín", "Tokio", "Nueva York"}, 2},
    {"¿Dónde está Transilvania?", {"En Serbia", "En Hungría", "En Rumanía", "En Bulgaria"}, 2},
    {"¿Cómo se llama el desierto de Aragón?", {"Desierto del Sáhara", "Desierto de los Monegros", "Desierto de Atacama", "Desierto de Gobi"}, 1},
    {"¿Qué río pasa por Valladolid?", {"El Ebro", "El Pisuerga", "El Duero", "El Tajo"}, 1},
    {"¿Cuál es el estado más grande de Estados Unidos?", {"Texas", "California", "Florida", "Alaska"}, 3},
    {"¿Qué dos países de América del Sur no tienen litoral?", {"Bolivia y Paraguay", "Bolivia y Chile", "Brasil y Argentina", "Paraguay y Ecuador"}, 0},
    {"¿Qué ciudad tuvo una vez el nombre de Leningrado?", {"Kiev", "Moscú", "San Petersburgo", "Volgogrado"}, 2},
    {"¿Cuál es la capital de Nicaragua?", {"Managua", "San Salvador", "Tegucigalpa", "Maragua"}, 0},
    {"Nombra un país que no tenga río.", {"Islandia", "Ciudad del Vaticano", "Andorra", "San Marino"}, 1},
    {"¿En qué lugar está el Taj Mahal?", {"Pekín", "Nueva Delhi", "Agra", "Karachi"}, 2},
    {"¿Cuántos países tiene Europa?", {"40", "45", "50", "55"}, 2},
    {"¿Dónde está el monte Vesubio?", {"Roma", "Nápoles", "Florencia", "Sicilia"}, 1},
    {"¿Cuántos huesos hay en el cuerpo humano?", {"206", "210", "215", "200"}, 0},
    {"¿Cómo se llaman las crías de los conejos?", {"Conejitos", "Gazapos", "Lechones", "Corderitos"}, 1},
    {"¿Cuántas válvulas tiene el corazón humano?", {"Cinco", "Tres", "Cuatro", "Seis"}, 2},
    {"¿Cómo se llama el proceso por el cual las plantas se alimentan?", {"Fotosíntesis", "Respiración", "Germinación", "Evaporación"}, 0},
    {"¿Cuál es el músculo más fuerte del cuerpo humano?", {"Bíceps", "Glúteo", "Masetero", "Trapezoide"}, 2},
    {"¿Cuántos elementos hay en la Tabla Periódica?", {"102", "118", "125", "100"}, 1},
    {"¿Cuánto vale el número pi?", {"3.1416", "3.14", "2.718", "3.15"}, 0},
    {"¿Qué elemento de la tabla periódica tiene como símbolo He?", {"Helio", "Hidrógeno", "Helio", "Hafnio"}, 0},
    {"¿Qué planeta es el que se encuentra más cercano al Sol?", {"Venus", "Tierra", "Marte", "Mercurio"}, 3},
    {"¿Qué es más grande, un átomo o una célula?", {"Célula", "Átomo", "Ambos son iguales", "Depende del tipo de célula"}, 0},
    {"¿Cuál es el animal más grande de la Tierra?", {"Elefante africano", "Ballena azul", "Tiburón blanco", "Jirafa"}, 1},
    {"¿Cuántos lados tiene un heptadecágono?", {"Quince", "Dieciséis", "Diecisiete", "Dieciocho"}, 2},
    {"¿De dónde sale el aceite de oliva?", {"De las nueces", "De los aguacates", "De las aceitunas", "De las uvas"}, 2},
    {"¿Cómo se llama el satélite más grande de Saturno?", {"Titán", "Europa", "Ganimedes", "Io"}, 0},
    {"¿Cuál es el único mamífero capaz de volar?", {"Murciélago", "Ardilla voladora", "Colibrí", "Murciégalo"}, 0},
    {"¿Quién pintó 'La última cena'?", {"Donatello", "Leonardo DaVinci", "Miguel Ángel", "Rafael"}, 1},
    {"¿En qué año nació Salvador Dalí?", {"1902", "1898", "1900", "1904"}, 3},
    {"¿Quién pintó el 'Guernica'?", {"Pablo Picasso", "Henri Matisse", "Diego Rivera", "Salvador Dalí"}, 0},
    {"¿Quién pintó 'Las Meninas'?", {"Francisco de Goya", "El Greco", "Velázquez", "Diego Rivera"}, 2},
    {"¿Dónde nació Van Gogh?", {"Madrid, España", "Ámsterdam, Países Bajos", "Zundert, Países Bajos", "París, Francia"}, 2},
    {"¿Quién pintó la 'Capilla Sixtina'?", {"Miguel Ángel", "Tiziano", "Leonardo DaVinci", "Rafael"}, 0},
    {"¿En qué museo se encuentra la obra original 'La noche estrellada', de Van Gogh?", {"Museo del Prado, Madrid", "Museo Van Gogh, Ámsterdam", "Museo de Arte Moderno de Nueva York", "Museo Louvre, París"}, 2},
    {"¿Quién es el padre del arte pop?", {"Keith Haring", "Jackson Pollock", "Andy Warhol", "Roy Lichtenstein"}, 2},
    {"¿Quién pintó la obra 'Diego y yo'?", {"Pablo Picasso", "Salvador Dalí", "Frida Kahlo", "Diego Rivera"}, 2},
    {"¿Cuándo surgió el vanguardismo?", {"A finales del siglo XVIII", "En la Edad Media", "A inicios del siglo XX", "A mediados del siglo XIX"}, 2},
    {"¿Dónde está el 'Guernica'?", {"Museo Reina Sofía, Madrid", "Museo de Bellas Artes, Bilbao", "Museo del Louvre, París", "Museo de Arte Moderno, Nueva York"}, 0},
    {"¿Cuál es el museo más antiguo de España?", {"Museo de Bellas Artes, Bilbao", "Museo Guggenheim", "Museo Nacional de Ciencias Naturales", "Museo del Prado"}, 3},
    {"¿Cuál es el nombre del cuadro más famoso de Edvard Munch?", {"El beso", "El abrazo", "El grito", "El sueño"}, 2},
    {"¿Cómo se llama la escultura más famosa de Auguste Rodin?", {"El pensador", "El beso", "La libertad guiando al pueblo", "El David"}, 0},
    {"¿Quién pintó 'La noche estrellada'?", {"Van Gogh", "Pablo Picasso", "Claude Monet", "Leonardo DaVinci"}, 0},
    {"¿Quién escribió 'El Quijote'?", {"Gabriel García Márquez", "William Shakespeare", "Dante Alighieri", "Miguel de Cervantes"}, 3},
    {"¿Quién escribió 'Hamlet'?", {"J.K. Rowling", "Miguel de Cervantes", "Camilo José Cela", "William Shakespeare"}, 3},
    {"¿Cuál es el primer libro de la Biblia?", {"El Génesis", "El Éxodo", "Los Salmos", "El Apocalipsis"}, 0},
    {"¿Quién escribió la famosa novela de 'Drácula'?", {"Mary Shelley", "Bram Stoker", "Edgar Allan Poe", "H.P. Lovecraft"}, 1},
    {"¿Quién escribió 'Cien años de soledad'?", {"Mario Vargas Llosa", "Pablo Neruda", "Gabriel García Márquez", "Julio Cortázar"}, 2},
    {"¿Quién escribió la ‘Divina Comedia’?", {"Petrarca", "Virgilio", "Geoffrey Chaucer", "Dante Alighieri"}, 3},
    {"¿Quién escribió 'La colmena'?", {"Ramón del Valle-Inclán", "Camilo José Cela", "Juan Ramón Jiménez", "Miguel de Unamuno"}, 1},
    {"¿Quién escribió 'Harry Potter'?", {"George R.R. Martin", "J.R.R. Tolkien", "J.K. Rowling", "Suzanne Collins"}, 2},
    {"¿Cuál es el libro más vendido de la historia?", {"La Biblia", "El Señor de los Anillos", "Cien años de soledad", "Don Quijote de la Mancha"}, 0},
    {"¿Cuál es el libro sagrado del Islam?", {"El Talmud", "La Torá", "La Biblia", "El Corán"}, 3},
    {"¿Quién fue el vocalista de Queen?", {"Mick Jagger", "Freddie Mercury", "Axl Rose", "Jim Morrison"}, 1},
    {"¿Cómo se llama realmente The Weeknd?", {"Abel Tesfaye", "Trevor Smith", "Michael Jackson", "Shawn Mendes"}, 0},
    {"¿Cuál es el disco más vendido de la historia?", {"'Back in Black', de AC/DC", "'The Dark Side of the Moon', de Pink Floyd", "'Thriller', de Michael Jackson", "'The Bodyguard', de Whitney Houston"}, 2},
    {"¿Qué cantante americana tiene un Óscar?", {"Beyoncé", "Adele", "Lady Gaga", "Jennifer Lopez"}, 2},
    {"¿Cómo se llama el último disco de Rosalía?", {"'El Mal Querer'", "'El Modo de la Luna'", "'Motomami'", "'Feliz Cumpleaños'"}, 2},
    {"¿Cuántas cuerdas tiene un violín?", {"Tres", "Cuatro", "Seis", "Cinco"}, 1},
    {"¿Cuál es el nombre real de Eminem?", {"Marshall Mathers", "Curtis James Jackson", "Shawn Corey Carter", "Robert Matthew Van Winkle"}, 0},
    {"¿Cómo se llama el himno nacional de Francia?", {"La Marsellesa", "O Canada", "God Save the Queen", "Advance Australia Fair"}, 0},
    {"¿En qué año murió Elvis Presley?", {"1980", "1977", "1965", "1992"}, 1},
    {"¿Quién es la artista femenina más escuchada en Spotify?", {"Adele", "Billie Eilish", "Taylor Swift", "Ariana Grande"}, 2}
};

vector<Question> getQuestions() {
    return questions;
}

Question getQuestion(int index) {
    if (index >= 0 && index < questions.size()) {
        return questions[index];
    } 
}
