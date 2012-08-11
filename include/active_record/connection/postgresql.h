#ifndef _ACTIVE_RECORD_CONNECTION_POSTGRESQL_H_
#define _ACTIVE_RECORD_CONNECTION_POSTGRESQL_H_

#include <postgresql/libpq-fe.h>
#include <active_record/connection.h>

namespace ActiveRecord {

class PostgresqlConnection : public Connection {
 public:
  PostgresqlConnection();
  virtual ~PostgresqlConnection();

  /* 
   * connection - an existing database connect to be used to issue the CREATE DATABASE command
   * options:
   *   database   - the name of the database to be created (or file name for SQLite3)
   *   owner      - (optional)
   *   template   - (optional)
   */
  static bool           create_database( PostgresqlConnection &connection, OptionsHash options );
  static void           drop_database( PostgresqlConnection & connection, const string &database_name );
  static bool           database_exists( PostgresqlConnection & connection,
                                         const string &database_name );

  virtual void          connect( OptionsHash options );
  virtual void          disconnect();
  virtual bool          connected();

  // Database Structure
  virtual bool          table_exists( const string &table_name );
  // Queries
  virtual bool          execute( const string &query,
                                 const AttributeList &parameters = AttributeList() );
  virtual long          insert( const string &query,
                                const AttributeList &parameters = AttributeList() );
  //virtual Attribute     select_value( const string &query,
  //                                    const AttributeList &parameters = AttributeList() );
  virtual AttributeList select_values( const string &query,
                                       const AttributeList &parameters = AttributeList() );
  virtual Row           select_one( const string &query,
                                    const AttributeList &parameters = AttributeList() );
  virtual RowSet        select_all( const string &query,
                                    const AttributeList &parameters = AttributeList() );
 private:
  PostgresqlConnection( const PostgresqlConnection& other );
  PostgresqlConnection operator=( const PostgresqlConnection& other );

  bool                  is_error( PGresult *exec_result );
  void                  log_error( PGresult *exec_result );

  PGconn *              pgconn_;
};

} // namespace ActiveRecord

#endif // ndef _ACTIVE_RECORD_CONNECTION_POSTGRESQL_H_

