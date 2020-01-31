Krzysztof Blankiewicz
293082

Problem:
Złodziej zdemaskowany w pewnym mieście ucieka z kraju - musi przedostać się do jakiegoś granicznego miasta. 
Po drodze ma przejechać przez możliwie najmniej miast (aby zminimalizowac ryzyko złapania). 
W trakcie ucieczki złodziej może  rabować odwiedzone miasta, jednak tak aby zmieścić pozyskane łupy w bagażniku o danej objętości. 
Każde miasto ma okresloną ilość (objętość) dóbr o określonej wartości możliwych do zrabowania. 
Spośród najsłabiej zurbanizowanych ścieżek złodziej ma wybrać tę najbardziej dochodową.

Dane wejściowe:
Dane wejściowe znajdują się w pliku "data.txt" umieszczonym w folderze z plikiem wykonywalnym. Przykładowe dane wejściowe znajdują się już w pliku.
W aplikację wbudowany jest generator danych losowych. Umieszcza on w pliku data.txt odpowiednią zawartość.

Uruchamianie programu:
Aplikację Thief.exe uruchamiamy z konsoli podając 6 parametrów wykonania.
./Thief.exe p1 p2p p3 p4 p5 p6
1. tryb wykonania (p1 == "graphic" => tryb graficzny; p1 != "graphic" => tryb klasyczny służący do pomiarów czasu)
2. generacja danych (p2 == "gen" => generacja danych przed uruchomieniem; p2 != "gen" wykorzystanie danych z data.txt)
3. rozmiar danych (p3 = szerokość mapy liczona w miastach)
4. liczba pomiarów czasu po których program uśrednia wynik (argument ignorowany w trybue graficznym)
5. ilość różnych wielkości problemu, dla których chcemy wykonać pomiar czasu wykonania (argument ignorowany w trybie graficznym)
6. przyrost wielkości problemu w kolejnych podejściach (argument ignorowany w trybue graficznym)
np.: 
	"./Thief.exe graphic gen 15 0 0 0" wyświetli (na podstawie wygenerowanych danych) wizualizację grafu o szerokości max. 15 miast ze znalezioną drogą ucieczki.
	"./Thief.exe n n 200 10 5 100" wyświetli uśrednione po 10 pomiarach czasy wykonania programu dla rozmiarów danych: 200, 300, 400, 500, 600

Dane wyjściowe:
W trybie graficznym na grafie zobaczymy zaznaczone na fioletowo najkrótsze ścieżki oraz żółtą, najbardziej opłacalną z nich, ścieżkę
W trybie klasycznym otrzymamy proste zestawienie rozmiarów danych i uśrednionych czasów wykoniania, w kolejnych liniach dla kolejnych rozmiarów.
Identyczne zestawienie jest dopisywane na koniec pliku out.txt w folderze z plikiem wykonywalnym.

Informacje dotyczące metod, algorytmów, wydajności znajdują się w dokumentacji.