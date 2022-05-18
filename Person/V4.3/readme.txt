//read "last inserted Id" when statement of Primary key is AUTO_INCREMENT. The PK can be easily brought.


SQLITE_API sqlite3_int64 sqlite3_last_insert_rowid(sqlite3*);

SQLITE_API void sqlite3_set_last_insert_rowid(sqlite3*,sqlite3_int64);
