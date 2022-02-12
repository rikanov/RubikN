#ifndef ___BIT64_SET__H
#define ___BIT64_SET__H

#include <cstdint>
#include <initializer_list>
#include <text_output.h>
#include <math.h>

template< typename Type > // unsigned integers
class BitSet
{
  Type m_data;

public:
  constexpr BitSet(): m_data( 0 ) {}
  constexpr BitSet( const Type & data ): m_data( data ) {}
  constexpr BitSet( const std::initializer_list<Type> & iList )
    : m_data( 0 )
  {
    for ( auto P : iList )
    {
      add( P );
    }
  }

  operator Type & ()
  {
    return m_data;
  }

  constexpr operator const Type & () const
  {
    return m_data;
  }

  constexpr bool notEmpty() const
  {
    return m_data > 0;
  }

  constexpr void set( const Type ds )
  {
    m_data = ds;
  }

  constexpr bool restrict( const BitSet & bm )
  {
    m_data &= bm.m_data;  // set intersection
    return 0 != m_data;
  }

  constexpr Type restrict( const Type rs )
  {
    m_data &= rs; // set intersection
    return m_data;
  }

  constexpr void expand( const BitSet & bm )
  {
    m_data |= bm.m_data;  // set union
  }

  constexpr void expand( const Type rs )
  {
    m_data |= rs;  // set union
  }

  constexpr void exclude( const Type rs )
  {
    m_data -= ( m_data & rs );
  }

  constexpr bool contains( const size_t bit ) const
  {
    return m_data & ( 1ULL << bit );
  }

  constexpr bool isLowBound( const uint8_t id ) const
  {
    return ( m_data & ( ( 1ULL <<  id ) - 1 ) ) == 0 ;
  }

  constexpr bool isHighBound( const uint8_t id ) const
  {
    return m_data <= ( 1ULL << id );
  }

  bool operator >> ( uint8_t & next )
  {
    if ( 0 == m_data )
    {
      return false;
    }
    // the rightmost high bit ie the smallest member of the set
    next =  __builtin_ctzl( m_data );
    m_data -= ( 1ULL << next );
    return true;
  }

  uint8_t pop()
  {
    // the rightmost high bit ie the smallest member of the set
    const Type least =  __builtin_ctzl( m_data );
    m_data -= ( 1ULL << least );
    return least;
  }

  constexpr void add( const size_t bit )
  {
    m_data |= ( 1ULL << bit );
  }

  constexpr void remove( const size_t bit )
  {
    exclude( 1ULL << bit );
  }

  void print_( const uint8_t length, const uint8_t slice ) const;
  void print ( const uint8_t length, const uint8_t slice ) const;

};

template< typename Type >
void BitSet<Type>::print_(const uint8_t length, const uint8_t slice) const
{
  const Color::Modifier color[2] = { Color::blue, Color::green };
  for( long id = length - 1; id >= 0; --id )
  {
    if ( slice > 0 && ( length - 1 - id ) % slice == 0 )
    {
      slog_ ( "", Color::white, '|', Color::off );
    }
    uint64_t mask = ( 1ULL << id );
    const bool bit = ( m_data & mask ) == mask;
    slog_ ( "", color[bit], bit, Color::off );
  }
}

template< typename Type >
void BitSet<Type>::print(const uint8_t length, const uint8_t slice) const
{
  print_( length, slice );
  NL();
}

#endif  //  ! ___BIT64_SET__H
