class StudentMarks
{
    enum {max_length = 100};
    short marks[max_length] {0}; // массив оценок студента
    int count {0}; // количество оценок в массиве marks
public:
    StudentMarks(short* ms, int total)
    {
        count = (total > max_length) ? max_length : total;

        for(int i = 0; i < count; ++i)
            marks[i] = ms[i];
    }

    StudentMarks operator+(StudentMarks right) const
    {
      int res_count = count + right.count > max_length ? max_length : count + right.count;
      short* res_marks = new short[res_count]{};
      for(int i = 0; i < res_count; ++i){
        if(i < count)
          res_marks[i] = marks[i];
        else
          res_marks[i] = right.marks[i - count];
      }
      return StudentMarks(res_marks, res_count);
   }
    StudentMarks operator+(int right) const
    {
        if(count == max_length)
          return *this;
        short* res_marks = new short[count + 1]{};
        for(int i = 0; i < count; ++i)
            res_marks[i] = marks[i];
        res_marks[count] = right;
        return StudentMarks(res_marks, count + 1);
    }

    const short* get_marks() const { return marks; }
    int get_count() const { return count; }
};

