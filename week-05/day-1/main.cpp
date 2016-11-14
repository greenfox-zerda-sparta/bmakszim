#include <iostream>
#include <string>
#include "Song.hpp"
#include "Rock.hpp"
#include "Pop.hpp"
#include "Reggae.hpp"
#include "Jukebox.hpp"

using namespace std;

int main() {
  Rock r01("Radiohead", "Decks Dark"); r01.rate(5); r01.rate(5); r01.rate(4); r01.rate(1); r01.rate(4);
  Rock r02("Pink Floyd", "Careful with that Axe, Eugene"); r02.rate(5); r02.rate(4); r02.rate(4); r02.rate(4);
  Rock r03("Pink Floyd", "Echoes"); r03.rate(5); r03.rate(5); r03.rate(4); r03.rate(4);
  Rock r04("Pink Floyd", "Time"); r04.rate(1); r04.rate(3); r04.rate(4); r04.rate(4);
  Rock r05("The Doors", "People Are Strange"); r05.rate(1); r05.rate(5); r05.rate(4); r05.rate(4);
  Rock r06("The Doors", "The Crystal Ship"); r06.rate(4); r06.rate(5); r06.rate(3); r06.rate(4);
  Rock r07("The Beatles", "I Want You(She's So Heavy"); r07.rate(4); r07.rate(4); r07.rate(4); r07.rate(4);
  Rock r08("The Beatles", "While My Guitar Gently Weeps"); r08.rate(4);
  Rock r09("Joy Division","New Dawn Fades"); r09.rate(4); r09.rate(3);
  Rock r10("Joy Division", "Day of the Lords"); r10.rate(4); r10.rate(5);
  Pop p1("Junior Senior", "Move Your Feet"); p1.rate(1); p1.rate(5); p1.rate(4); p1.rate(4); p1.rate(4);
  Pop p2("Rihanna", "Love On The Brains"); p2.rate(2); p2.rate(1); p2.rate(5); p2.rate(4); p2.rate(4);
  Pop p3("Rihanna", "Umbrella"); p3.rate(4); p3.rate(4); p3.rate(5); p3.rate(1); p3.rate(4);
  Pop p4("LP", "Lost On You"); p4.rate(5); p4.rate(1); p4.rate(2); p4.rate(3);
  Pop p5("Twenty One Pilots", "Heathens"); p5.rate(5); p5.rate(5); p5.rate(2); p5.rate(3);
  Pop p6("Adele", "River Lea"); p6.rate(4); p6.rate(3); p6.rate(2);
  Pop p7("Adele", "Hello"); p7.rate(2); p7.rate(3); p7.rate(4);
  Pop p8("Adele", "Someone Like You"); p8.rate(3); p8.rate(4); p8.rate(2);
  Reggae z1("Bob Marley", "Is This Love"); z1.rate(3); z1.rate(3); z1.rate(4);
  Reggae z2("Bob Marley", "Could You Be Loved"); z2.rate(3); z2.rate(3);
  Reggae z3("Bob Marley", "No Woman, No Cry"); z3.rate(1); z3.rate(4);
  Reggae z4("Bob Marley", "Three Little Birds"); z4.rate(1); z4.rate(5);

  Jukebox jukebox;
  jukebox.add_song(r01);
  jukebox.add_song(r02);
  jukebox.add_song(r03);
  jukebox.add_song(r04);
  jukebox.add_song(r05);
  jukebox.add_song(r06);
  jukebox.add_song(r07);
  jukebox.add_song(r08);
  jukebox.add_song(r09);
  jukebox.add_song(r10);
  jukebox.add_song(p1);
  jukebox.add_song(p2);
  jukebox.add_song(p3);
  jukebox.add_song(p4);
  jukebox.add_song(p5);
  jukebox.add_song(p6);
  jukebox.add_song(p7);
  jukebox.add_song(p8);
  jukebox.add_song(z1);
  jukebox.add_song(z2);
  jukebox.add_song(z3);
  jukebox.add_song(z4);
  cout << "Avrg rating of r04: " << r04.get_rating() << endl;
  jukebox.rate_song("Pink Floyd", "Time", 4);
  cout << "Avrg rating of r04 after rating by artist+title: " << r04.get_rating() << endl;
  cout << "Avrg song rating of Pink Floyd: " << jukebox.get_artist_rating("Pink Floyd") << endl;
  cout << "Avrg rating of rock: " << jukebox.get_genre_rating("rock") << endl;
  cout << "Avrg rating of pop: " << jukebox.get_genre_rating("pop") << endl;
  cout << "Avrg rating of reggae: " << jukebox.get_genre_rating("reggae") << endl;
  cout << "Top rated title(s): " << jukebox.get_top_rated_title() << endl;
  cout << "Top rated genre(s): " << jukebox.get_top_rated_genre() << endl;
  return 0;
}
