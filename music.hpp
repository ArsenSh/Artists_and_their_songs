
Song::Song()
{
    std::cout << "Enter the name of the song: ";
    std::cin >> song_name;
    std::cout << "Enter the date of publishment: ";
    std::cin >> data;
    std::cout << "Enter the name of the publisher: ";
    std::cin >> publisher;
    std::cout << "Enter duration of the song " << song_name << ": ";
    std::cin >> duration;
}

std::string Song::get_song_name() const {return song_name;}
u_short Song::get_data() const {return data;}
std::string Song::get_publisher() const {return publisher;}
u_int Song::get_song_duration() const {return duration;}

Song::~Song(){}

Musician::Musician()
{
    u_int count = 0;
    std::string song = "";
    std::cout << "Enter the name of the artist: ";
    std::cin >> name;
    std::string tmp = "";
    do{
        std::cout << "If the artict has surename enter 'yes', otherwise 'no': ";
        std::cin >> tmp;
    }while(tmp != "yes" && tmp != "no");
    if(tmp == "yes")
    {
        std::cout << "Enter the surename: ";
        std::cin >> surename;
    }
    std::cout << "Enter the nationality of that singer: ";
    std::cin >> country;
    std::cout << "Enter the year of " << name << " birth: ";
    std::cin >> yearOfBirth;
    std::cout << "Enter the amount of songs of " << name << " " << surename << ": ";
    std::cin >> count;
    for(int i = 0; i < count; i++)
    {
        std::cout << "Enter the " << i + 1 << "# song: ";
        std::cin >> song;
        allsongs.push_back(song);
    }
}

std::string Musician::get_name() const {return name;}
std::string Musician::get_surename() const {return surename;}
std::string Musician::get_country() const {return country;}
u_short Musician::get_birth() const {return yearOfBirth;}
std::vector <std::string> Musician::get_songs() const {return allsongs;}

Musician::~Musician(){}

void musician()
{
    int choice = 0;
    std::cout << "Select the operation that you prefer below." << std::endl;
    std::cout << "\t[1] Insert song\t\n" << "\t[2] Insert Musician \t\n" << "\t[3] Search song \t\n" << "\t[4] Search musician \t\n" << "\t[5] Add song \t\n" << "\t[6] Remove song \t\n" << "\t[7] Add to favorits \t\n" << "\t[8] EXIT \t" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;
    operation(choice);
}

void operation(int choice)
{
    switch(choice)
    {
        case 1:
            song_insertion();
            musician();
            break;
        case 2:
            musician_insertion();
            musician();
            break;
        case 3:
            song_searching();
            musician();
            break;
        case 4:
            musician_searching();
            musician();
            break;
        case 5:
            adding_song();
            musician();
            break;
        case 6:
            removing_song();
            musician();
            break;
        case 7:
            adding_to_favourits();
            musician();
            break;
        case 8:
            exit(0);
            
        default:
            std::cout << "There is no that kind of operation, enter the correct index: ";
            int tryagain = 0;
            std::cin >> tryagain;
            operation(tryagain);
    }
}

void song_insertion()
{
    u_int amount = 0;
    std::cout << "Enter the amount of songs you want to insert: ";
    std::cin >> amount;
    for(int i = 0; i < amount; i++)
    {
        Song song;
        cloud.cloud_s.push_back(song);
        std::cout << "The " << song.get_song_name() << " song is added to cloud successfully" << std::endl;
    }
}

void musician_insertion()
{
    u_int amount = 0;
    std::cout << "Enter the amount of artists you want to insert: ";
    std::cin >> amount;
    for(int i = 0; i < amount; i++)
    {
        Musician musician;
        cloud.cloud_m.push_back(musician);
        std::cout << "The " << musician.get_name() << " artist is added to cloud successfully" << std::endl;
    }
}

void song_searching()
{
    std::string songname = "";
    std::cout << "Enter the name of song you want to search: ";
    std::cin >> songname;
    for(int i = 0; i < favour.favourite_s.size(); ++i)
    {
        if(songname == favour.favourite_s[i].get_song_name())
        {
            std::cout << "That song " << songname << " is located in favourits" << std::endl;
            std::cout << "The artist name of " << songname << ": " << favour.favourite_s[i].get_publisher() << std::endl;
            std::cout << songname << " song duration " << favour.favourite_s[i].get_song_duration() << std::endl;
            std::cout << "Year of coming light is " << favour.favourite_s[i].get_data() << std::endl;
            return;
        }
    }
    for(int i = 0; i < cloud.cloud_s.size(); ++i)
    {
        if(songname == cloud.cloud_s[i].get_song_name())
        {
            std::cout << "That song " << songname << " is located in cloud" << std::endl;
            std::cout << "The artist name of " << songname << ": " << cloud.cloud_s[i].get_publisher() << std::endl;
            std::cout << songname << " song duration " << cloud.cloud_s[i].get_song_duration() << std::endl;
            std::cout << "Year of coming light is " << cloud.cloud_s[i].get_data() << std::endl;
            return;
        }
    }
    std::cout << "Nothing found by this name: " << songname << std::endl;
}

void musician_searching()
{
    std::string artistname = "";
    std::cout << "Enter the name of artist you want to search: ";
    std::cin >> artistname;
    for(int i = 0; i < favour.favourite_m.size(); ++i)
    {
        if(artistname == favour.favourite_m[i].get_name())
        {
            std::cout << "That artist " << artistname << " is located in favourits" << std::endl;
            std::cout << "The surename of " << artistname << " is: " << favour.favourite_m[i].get_surename() << std::endl;
            std::cout << "The date of birth is: " << favour.favourite_m[i].get_birth() << std::endl;
            std::cout << "Country is: " << favour.favourite_m[i].get_country() << std::endl;
            std::cout << "Below is the list of songs" << std::endl;
            for(int j = 0; j < favour.favourite_m[i].get_songs().size(); ++i)
            {
                std::cout << "\t" << j + 1 << "# song: " << favour.favourite_m[i].get_songs()[j] << "\t" << std::endl;
            }
            return;
        }
    }
    for(int i = 0; i < cloud.cloud_m.size(); ++i)
    {
        if(artistname == cloud.cloud_m[i].get_name())
        {
            std::cout << "That artist " << artistname << " is located in cloud" << std::endl;
            std::cout << "The surename of " << artistname << " is: " << cloud.cloud_m[i].get_surename() << std::endl;
            std::cout << "The date of birth is: " << cloud.cloud_m[i].get_birth() << std::endl;
            std::cout << "Country is: " << cloud.cloud_m[i].get_country() << std::endl;
            std::cout << "Below is the list of songs" << std::endl;
            for(int j = 0; j < cloud.cloud_m[i].get_songs().size(); ++i)
            {
                std::cout << "\t" << j + 1 << "# song: " << cloud.cloud_m[i].get_songs()[j] << "\t" << std::endl;
            }
            return;
        }
    }
}

void adding_song()
{
    std::cout << "Enter the information about your song\n";
    Song song;
    cloud.cloud_s.push_back(song);
    std::cout << song.get_song_name() << " is added into cloud successfully" << std::endl;
}

void removing_song()
{
    std::string songname = "";
    std::cout << "Enter the name of the song: ";
    std::cin >> songname;
    for(int i = 0; i < cloud.cloud_s.size(); ++i)
    {
        cloud.cloud_s.erase(cloud.cloud_s.begin() + i);
        std::cout << songname << " is removed from the cloud successfully" << std::endl;
        return;
    }
    std::cout << "Nothing found by the name " << songname << std::endl;
}

void adding_to_favourits()
{
    std::string tmp = "";
    do{
        std::cout << "What you prefer to add 'Song' or 'Musician': ";
        std::cin >> tmp;
    }while(tmp != "Song" && tmp != "Musician");
    if(tmp == "Song")
    {
        std::cout << "Enter the informations about the song" << std::endl;
        Song song;
        favour.favourite_s.push_back(song);
        std::cout << "Song is added inside favourits successfully" << std::endl;
    }
    else if(tmp == "Musician")
    {
        std::cout << "Enter the informations about the musician" << std::endl;
        Musician musician;
        favour.favourite_m.push_back(musician);
        std::cout << "Musician is added inside favourits successfully" << std::endl;
    }
}
