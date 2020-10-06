//
// ex: set ro:
// DO NOT EDIT.
// generated by smc (http://smc.sourceforge.net/)
// from file : recognizer.sm
//

#ifndef RECOGNIZER_SM_H
#define RECOGNIZER_SM_H


#define SMC_USES_IOSTREAMS

#include "statemap.h"

// Forward declarations.
class FSMMap;
class FSMMap_Start;
class FSMMap_Static_part;
class FSMMap_Name;
class FSMMap_Size;
class FSMMap_Hash;
class FSMMap_Ending;
class FSMMap_OK;
class FSMMap_Error;
class FSMMap_Default;
class FSMSolutionState;
template<typename DERIVED> class recognizerContext;
class FSMSolution;

class FSMSolutionState :
	public statemap::State
{
public:

	FSMSolutionState( const char * const name,const int stateId )
		: statemap::State( name,stateId )
	{};

	virtual void Entry( recognizerContext<FSMSolution>& ) {};
	virtual void Exit( recognizerContext<FSMSolution>& ) {};

	virtual void EOS( recognizerContext<FSMSolution>& context );
	virtual void symb( recognizerContext<FSMSolution>& context,char c );

protected:

	virtual void Default( recognizerContext<FSMSolution>& context );
};

class FSMMap
{
public:

	static FSMMap_Start Start;
	static FSMMap_Static_part Static_part;
	static FSMMap_Name Name;
	static FSMMap_Size Size;
	static FSMMap_Hash Hash;
	static FSMMap_Ending Ending;
	static FSMMap_OK OK;
	static FSMMap_Error Error;
};

class FSMMap_Default :
	public FSMSolutionState
{
public:

	FSMMap_Default( const char * const name,const int stateId )
		: FSMSolutionState( name,stateId )
	{};

	virtual void EOS( recognizerContext<FSMSolution>& context );
	virtual void symb( recognizerContext<FSMSolution>& context,char c );
};

class FSMMap_Start :
	public FSMMap_Default
{
public:
	FSMMap_Start( const char * const name,const int stateId )
		: FSMMap_Default( name,stateId )
	{};

	virtual void symb( recognizerContext<FSMSolution>& context,char c );
};

class FSMMap_Static_part :
	public FSMMap_Default
{
public:
	FSMMap_Static_part( const char * const name,const int stateId )
		: FSMMap_Default( name,stateId )
	{};

	virtual void symb( recognizerContext<FSMSolution>& context,char c );
};

class FSMMap_Name :
	public FSMMap_Default
{
public:
	FSMMap_Name( const char * const name,const int stateId )
		: FSMMap_Default( name,stateId )
	{};

	virtual void symb( recognizerContext<FSMSolution>& context,char c );
};

class FSMMap_Size :
	public FSMMap_Default
{
public:
	FSMMap_Size( const char * const name,const int stateId )
		: FSMMap_Default( name,stateId )
	{};

	virtual void symb( recognizerContext<FSMSolution>& context,char c );
};

class FSMMap_Hash :
	public FSMMap_Default
{
public:
	FSMMap_Hash( const char * const name,const int stateId )
		: FSMMap_Default( name,stateId )
	{};

	virtual void symb( recognizerContext<FSMSolution>& context,char c );
};

class FSMMap_Ending :
	public FSMMap_Default
{
public:
	FSMMap_Ending( const char * const name,const int stateId )
		: FSMMap_Default( name,stateId )
	{};

	virtual void symb( recognizerContext<FSMSolution>& context,char c );
};

class FSMMap_OK :
	public FSMMap_Default
{
public:
	FSMMap_OK( const char * const name,const int stateId )
		: FSMMap_Default( name,stateId )
	{};

	virtual void EOS( recognizerContext<FSMSolution>& context );
};

class FSMMap_Error :
	public FSMMap_Default
{
public:
	FSMMap_Error( const char * const name,const int stateId )
		: FSMMap_Default( name,stateId )
	{};

	virtual void symb( recognizerContext<FSMSolution>& context,char c );
};

template<typename DERIVED>
class recognizerContext :
	public statemap::FSMContext
{
public:

	explicit recognizerContext()
		: FSMContext( FSMMap::Start )
	{};

	recognizerContext( const statemap::State& state )
		: FSMContext( state )
	{};

	virtual void enterStartState()
	{
		getState().Entry( *this );
		return;
	}

	inline FSMSolution& getOwner()
	{
		return (*static_cast<DERIVED*>(this));
	};

	inline FSMSolutionState& getState()
	{
		if ( _state == NULL )
		{
			throw statemap::StateUndefinedException();
		}

		return dynamic_cast<FSMSolutionState&>(*_state);
	};

	inline void EOS()
	{
		getState().EOS( *this );
	};

	inline void symb( char c )
	{
		getState().symb( *this,c );
	};
};


#endif // RECOGNIZER_SM_H

//
// Local variables:
//  buffer-read-only: t
// End:
//
