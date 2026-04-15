public abstract class Book {
    private String Title;
    private String Author;
    private String Status;


    public Book(String Title , String Author) {
        this.Title = Title;
        this.Author = Author;
        this.Status = "Available";
    }


    public String getTitle() {
        return this.Title;
    }

    public String getAuthor() {
        return this.Author;
    }

    public String getStatus() {
        return this.Status;
    }
    public void setStatus(String Status) {
        this.Status = Status;
    }

    
    abstract public String displayInfo();
}
