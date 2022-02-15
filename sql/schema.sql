create table chapter
(
    id   integer,
    name integer
        constraint chapter_pk
            primary key autoincrement
);

create table choices
(
    id         integer not null
        constraint choices_pk
            primary key autoincrement,
    type       varchar(1),
    block      integer,
    content    text    not null,
    ans_1      varchar(250),
    ans_2      varchar(250),
    ans_3      varchar(250),
    ans_4      varchar(250),
    chapter_id integer
        constraint choices_chapter_id_fk
            references chapter (id)
            on update cascade on delete cascade
);

create table player
(
    id   INTEGER not null
        primary key autoincrement,
    name VARCHAR(50) default 'Rick' not null
);

create table games
(
    id         integer      not null
        constraint games_pk
            primary key autoincrement,
    player_id  INTEGER      not null
        references player
            on update cascade on delete cascade,
    finished   INTEGER,
    position   VARCHAR(255) not null,
    chapter_id integer      not null
        constraint games_chapter_id_fk
            references chapter (id)
            on update cascade on delete cascade
);
