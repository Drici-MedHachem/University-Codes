public class Livre {
    private String titre;
    private String auteur;
    private int nbpages;


    public Livre() {};
    public Livre(String titre , String auteur) {
        this.titre = titre;
        this.auteur = auteur;
    }
    public Livre(String titre , String auteur , int nbpages) {
        this.titre = titre;
        this.auteur = auteur;
        this.nbpages = nbpages;
    }

    public int getNbpages() {
        return this.nbpages;
    }

    public void setTitre(String titre) {this.titre = titre;}
    public void setAuteur(String auteur) {this.auteur = auteur;}
    public void setNbpages(int nbpages) {this.nbpages = nbpages;}


    @Override
    public String toString() {
        return "[" + this.titre + " / " + this.auteur + " / " + this.nbpages + "p]";
    }

    public static void main(String[] args) {
        Livre l1 = new Livre("Clean Code" , "Robert Martin" , 464);
        Livre l2 = new Livre("1948" , "Orwell");
        Livre l3 = new Livre();

        l2.setNbpages(328);

        l3.setTitre("Dune");
        l3.setAuteur("Herbert");
        l3.setNbpages(896);

        System.out.println(l1.getNbpages());
        System.out.println(l1);
        System.out.println(l2);
    }
}
