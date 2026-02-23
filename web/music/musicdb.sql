DROP DATABASE IF EXISTS Music;
CREATE DATABASE IF NOT EXISTS Music;
USE Music;

CREATE TABLE IF NOT EXISTS Artist (
    artist_id INTEGER NOT NULL AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255)
);

CREATE TABLE IF NOT EXISTS Album (
    album_id INTEGER NOT NULL AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(50),
    artist_id INTEGER NOT NULL,

    INDEX USING BTREE (title),



    FOREIGN KEY (artist_id) REFERENCES Artist(artist_id) ON DELETE CASCADE
);


CREATE TABLE IF NOT EXISTS Genre (
    genre_id INTEGER NOT NULL AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255)
);

CREATE TABLE IF NOT EXISTS Track (
    track_id INTEGER NOT NULL AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(255),
    len INTEGER,
    rating INTEGER,
    count INTEGER,
    album_id INTEGER,
    genre_id INTEGER,

    INDEX USING BTREE (title),

    FOREIGN KEY (album_id) REFERENCES Album (album_id) ON DELETE CASCADE,
    FOREIGN KEY (genre_id) REFERENCES Genre (genre_id) ON DELETE CASCADE
);


INSERT INTO Artist (name) VALUES ('Led Zepplin') , ('AC/DC')  , ('Dedine Canon 16') , ('Red1') , ('Emimem') ;
INSERT INTO Genre (name) VALUES ('Rock') , ('Metal') , ('Rap') ; 
INSERT INTO Album (title,artist_id) VALUES ('Who Made Who',2) , ('IV' , 1);
INSERT INTO Track (title,len,rating,count,album_id,genre_id) VALUES ('Black Dog' , 297, 5 ,0,2,1) , ('Stairway' , 482 , 5, 0,2,1) , ('About to Rock' , 313 , 5, 0, 1, 2) , ('Who Made Who' , 207 , 5, 0, 1, 2);
