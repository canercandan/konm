function MM_preloadImages() { //v3.0
  var d=document; if(d.images){ if(!d.MM_p) d.MM_p=new Array();
    var i,j=d.MM_p.length,a=MM_preloadImages.arguments; for(i=0; i<a.length; i++)
    if (a[i].indexOf("#")!=0){ d.MM_p[j]=new Image; d.MM_p[j++].src=a[i];}}
}





function border_rouge(nom){
		window.document.getElementById(nom).style.border = "thin solid #FF0000";
}





function border_normale(nom){
window.document.getElementById(nom).style.borderWidth = '';
window.document.getElementById(nom).style.borderStyle = '';
window.document.getElementById(nom).style.borderColor = '';
}





function verify_form(arr){

for(i=0;i<arr.length;i++){border_normale(arr[i].id);};
var	ok=1;
var msg='.';

for(i=0;i<arr.length;i++){
	if(arr[i].value==""){border_rouge(arr[i].id);ok=0;};					// On test si le champs est rempli
	if((arr[i].id.indexOf("mail")>-1) || (arr[i].id.indexOf("Mail")>-1)){	// Si c'est un mail on teste la validité du mail
		adresse_email = arr[i].value;arobase = adresse_email.indexOf("@");point = adresse_email.indexOf(".",arobase);mauvais_endroit_point = arobase+1;
		double_point = adresse_email.indexOf("..",arobase);nbr_carac = adresse_email.length - point;double_arobase = adresse_email.indexOf("@",arobase+1);
		if((arobase < 1) || (point <= mauvais_endroit_point) || (adresse_email.length < 5) || (double_point >= 0) || (nbr_carac < 3) || (double_arobase >= 0))
		{msg=l_email_n_est_pas_valide;ok=0; border_rouge(arr[i].id);}
	}
};//for

	if(ok==0){alert(les_champs_en_rouge_sont_necessaires+msg);arr[0].focus();return false}
	if(ok==1)return true
}



function fc_port()
{
var radio_choice = false;
for (i = 0; i < window.document.forms.bon.frais_de_port.length; i++)
{
if (window.document.forms.bon.frais_de_port[i].checked)radio_choice = true; 
}

if (!radio_choice)
{
alert(veuillez_choisir_mode_expedtion);return false;
}
return true;
}




function cheque(){
	if(	window.document.forms.bon.conditions_vente.checked){
		window.open('blank.php', 'securecleserv','width=640,height=550,toolbar=no,location=no,directories=no,status=yes,menubar=no,scrollbars=yes,resizable=yes');
		window.document.forms.bon.target='securecleserv';
		window.document.forms.bon.type_paiement.value='Chèque';
		window.document.forms.bon.action='impression.php';
		return true;
	}
	else{
		alert(veuillez_accepter_les_cgv_avant_de_commander);
		return false;
	}
}




function carte_bleue_privee(){
	if(	window.document.forms.bon.conditions_vente.checked){
		window.open('blank.php', 'securecleserv','width=720,height=550,toolbar=no,location=no,directories=no,status=yes,menubar=no,scrollbars=yes,resizable=yes');
		window.document.forms.bon.target='securecleserv';
		window.document.forms.bon.type_paiement.value='Carte Bleue Aut';
		window.document.forms.bon.action='commande_transfert_ssl.php';
		return true;
		//window.document.forms.bon.submit();
	}
	else{
		alert(veuillez_accepter_les_cgv_avant_de_commander);
		return false;
	}
}




function id2element(id)
{
    if (!document.getElementById)return;
    if (document.all)return eval("document.all." + id);
    else
    return document.getElementById(id);
}



function toggle(id,type,collapse) 
{
	var x = window.document.getElementsByTagName(type);
		if(collapse==1){
			for (var i=0;i<x.length;i++){	x[i].style.display = 'none'; }
		}
	id2element(type + id).style.display = (id2element(type + id).style.display == "none" ? "block" : "none");
}

function DisplayNone(type) 
{
	var x = window.document.getElementsByTagName(type);
	for (var i=0;i<x.length;i++){	x[i].style.display = 'none'; }
}