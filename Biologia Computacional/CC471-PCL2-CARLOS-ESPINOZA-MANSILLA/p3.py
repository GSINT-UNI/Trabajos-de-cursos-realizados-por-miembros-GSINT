from Bio import SeqIO


print("parte 3.1 convertir PCL2.gb a PCL2.fasta\n\n")
input_filename = "PCL2.gb"
output_filename = "PCL2.fasta"
count = SeqIO.convert(input_filename, "gb", output_filename, "fasta")
print(str(count) + " registros convertidos\n")
print("PCL2.gb a PCL2.fasta: Conversion completa")

print("\nparte 3.2 crear PCLFILTRO.fasta con 3 registros de la pregunta 2\n\n")

infilename = "PCL2.gb"
outfilename = "PCLFILTRO.fasta"
count = 0

output_handle = open(outfilename, "w")
for record in SeqIO.parse(infilename, "gb"):    
	if record.seq[-4:] == "TFSL" :        	
       		SeqIO.write(record, output_handle, "fasta")
	count = count + 1
	if count > 2 : 
		break	
output_handle.close()


