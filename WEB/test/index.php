<?php
class Student {
    public $name = false;
    public $year = false;

    public function __construct($name , $year) {
        $this->name = $name;
        $this->year = $year;
    }

    public function infoStudent() {
        $info = $this->name . " " . $this-> year;
        echo $info;
    }
}


$student1 = new Student("Mohammed" , "Hachem");
$student1->infoStudent();
?>
