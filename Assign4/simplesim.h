#ifndef simplesim_h
#define simplesim_h
class simplesim
{
    private:
    int memory[100];
    int accumulator;
    int instruction_counter;
    int instruction_register;
    int operation_code;
    int operand;
	
	public:
	simplesim();
	bool load_program();
	void execute_program();
	void dump()const;
	
};


#endif
