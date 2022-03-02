create table chapter (
    id integer constraint chapter_pk primary key autoincrement,
    name varchar(50) not null,
    finished integer default 0 not null
);
create unique index chapter_name_index on chapter (name);

create table game (
    id integer constraint game_pk primary key autoincrement,
    chapter_id integer no t null references chapter,
    score integer not null
);

create table talk (
    id integer constraint talk_pk primary key autoincrement,
    chapter_id integer not null references chapter,
    sprite varchar(50),
    content varchar(255) not null
);

create table question (
    id integer constraint question_pk primary key autoincrement,
    talk_id integer not null references talk,
    points  integer not null,
    content varchar(255) not null,
    sprite  varchar(255),
    reply   varchar(255) not null
);

