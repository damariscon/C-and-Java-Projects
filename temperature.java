public class Temperature{
    private double ftemp;
    public Temperature(double ftemp){
        this.ftemp=ftemp;
    }
    public void setFahrenheit(double ftemp){
        this.ftemp=ftemp;
    }
    public double getFahrenheit(){
        return ftemp;
    }
    public double getCelsius(){
        double celsius=(5.0/9.0)*(ftemp-32);
        return celsius;
    }
    public double getKelvin(){
        double kelvin=((5.0/9.0)*(ftemp-32))+273;
        return kelvin;
    }
}
