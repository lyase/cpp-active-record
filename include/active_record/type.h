#ifndef _ACTIVE_RECORD_TYPE_H_
#define _ACTIVE_RECORD_TYPE_H_

#include <iostream> // For debugging
#include <map>
#include <string>

using namespace std;

namespace ActiveRecord {

// Attributes are typed
enum Type {
  unknown        = -1,
  integer        = 0,
  text           = 1,
  floating_point = 2,
  date           = 3
};

typedef pair< ActiveRecord::Type, string >    TypeNamePair;
typedef map< ActiveRecord::Type, string >     TypeNameMap;

Type index_to_type( int index );
Type to_type( const string &type_name );

} // namespace ActiveRecord

#endif // ndef _ACTIVE_RECORD_TYPE_H_
